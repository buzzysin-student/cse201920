module Edge where


import Vertex ( VertexPair, Vertex, vertexValue )
data Edge e v = Edge e (VertexPair v)
  deriving (Show, Eq)

edgeStart :: Edge e v -> Vertex v
edgeStart (Edge _ (u, _)) = u

edgeEnd :: Edge e v -> Vertex v
edgeEnd (Edge _ (_, v)) = v

edgeValue :: Edge e v -> e
edgeValue (Edge e _) = e

edgePairs :: Edge e v -> VertexPair v
edgePairs (Edge _ p) = p

edgePairsRaw :: Edge e a -> (a, a)
edgePairsRaw (Edge _ (u, v)) = (vertexValue u, vertexValue v)