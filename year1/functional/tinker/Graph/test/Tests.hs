import Base
  ( Graph (..),
    graphDegreeV,
    graphEdges,
    graphFromEdges,
    graphInDegreeV,
    graphOutDegreeV,
    graphVertices,
  )
import Edge
import Test.QuickCheck ()
import Vertex (Vertex (Vertex))

testGraphOne :: Graph Integer ()
testGraphOne =
  graphFromEdges
    [ Edge () (Vertex 1, Vertex 2),
      Edge () (Vertex 2, Vertex 3),
      Edge () (Vertex 3, Vertex 4),
      Edge () (Vertex 1, Vertex 5),
      Edge () (Vertex 5, Vertex 6),
      Edge () (Vertex 6, Vertex 7),
      Edge () (Vertex 5, Vertex 8),
      Edge () (Vertex 1, Vertex 9),
      Edge () (Vertex 9, Vertex 10)
    ]

-- ! TESTS

prop_graphBuilds :: (Eq v, Eq e) => Graph v e -> Bool
prop_graphBuilds (Graph vs es) =
  and
    [ b
      | (v1, v2) <- map edgePairs es,
        let b = (v1 `elem` vs) && v2 `elem` vs,
        b
    ]

prop_graphHandShaking :: Eq v => Graph v e -> Bool
prop_graphHandShaking g =
  sum (map (`graphDegreeV` g) vs) == 2 * length es
  where
    vs = graphVertices g
    es = graphEdges g

prop_graphValency :: Eq v => Graph v e -> Bool
prop_graphValency g =
  and
    [ b
      | v <- vs,
        let b =
              sum (map (`graphInDegreeV` g) vs)
                + sum (map (`graphOutDegreeV` g) vs)
                  == graphDegreeV v g,
        b
    ]
  where
    vs = graphVertices g
