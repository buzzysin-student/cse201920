module Base where

import Edge ( Edge(..), edgeStart, edgeEnd, edgePairs )
import Operators ( (+>), (+^) )
import System.Environment ( getArgs )
import Vertex ( Vertex(..) )

data Graph v e = Graph [Vertex v] [Edge e v]
  deriving (Show, Eq)

graphEmpty :: Graph v e
graphEmpty = Graph [] []

graphEdges :: Graph v e -> [Edge e v]
graphEdges (Graph _ es) = es

graphVertices :: Graph v e -> [Vertex v]
graphVertices (Graph vs _) = vs

-- in neighbours
graphIntoV :: Eq v => Vertex v -> Graph v e -> [Vertex v]
graphIntoV v (Graph vs es) = [u | u <- vs, (u, v) `elem` map edgePairs es]

-- out neighbours
graphOutOfV :: Eq v => Vertex v -> Graph v e -> [Vertex v]
graphOutOfV v (Graph vs es) = [w | w <- vs, (v, w) `elem` map edgePairs es]

-- both in and out neighbours
graphNextToV :: Eq v => Vertex v -> Graph v e -> [Vertex v]
graphNextToV v g = graphIntoV v g +^ graphOutOfV v g

graphInDegreeV :: Eq v => Vertex v -> Graph v e -> Int
graphInDegreeV v g = length (graphIntoV v g)

graphOutDegreeV :: Eq v => Vertex v -> Graph v e -> Int
graphOutDegreeV v g = length (graphOutOfV v g)

graphDegreeV :: Eq v => Vertex v -> Graph v e -> Int
graphDegreeV v g = graphInDegreeV v g + graphOutDegreeV v g

graphAddV :: Eq v => Vertex v -> Graph v e -> Graph v e
graphAddV v (Graph vs es) = Graph (v +> vs) es

graphAddE :: (Eq v, Eq e) => Edge e v -> Graph v e -> Graph v e
graphAddE (Edge e (v1, v2)) (Graph vs es) = Graph (v1 +> v2 +> vs) (Edge e (v1, v2) +> es)

graphFromEdges :: (Eq v, Eq e) => [Edge e v] -> Graph v e
graphFromEdges = foldr graphAddE graphEmpty

graphDFS :: Eq v => Vertex v -> Graph v e -> [Vertex v]
graphDFS v g = _graphDFS [v] w
  where
    w = head (graphOutOfV w g)
    _graphDFS discovered current
      | current `notElem` discovered = _graphDFS (discovered ++ [w]) current
      | otherwise = discovered

graphVisualise :: (Show v, Show e, Eq v) => Graph v e -> IO ()
graphVisualise (Graph vs es) = do
  args <- getArgs
  let filePath = head args
  writeFile
    (filePath ++ ".dot")
    ("digraph {\n" ++ details ++ "}")
  where
    details =
      concatMap
        ( \(Edge e (Vertex u, Vertex v)) ->
            show u ++ " -> " ++ show v ++ " [ label=\"" ++ show e ++ "\" ];" ++ "\n"
        )
        es
        ++ concatMap
          (\(Vertex v) -> show v ++ "\n")
          [v | v <- vs, v `notElem` map edgeStart es ++ map edgeEnd es]