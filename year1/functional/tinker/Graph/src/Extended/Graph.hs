module Extended.Graph where

import Base (Graph, graphEdges, graphFromEdges, graphVertices)
import Extended.Edge (pieNormalise)
import Extended.Vertex (pivNormalise)
import Test.QuickCheck (Arbitrary (arbitrary), Positive, getPositive)
import Vertex (Vertex (..), vertexValue)
import Edge (edgePairs)

instance (Eq vs, Eq es, Arbitrary vs, Arbitrary es) => Arbitrary (Graph vs es) where
  arbitrary = do graphFromEdges <$> arbitrary

newtype PIGraph = PIGraph {getPIGraph :: Graph (Positive Integer) (Positive Integer)}

pigNormalise pig = Graph vs es
  where
    es = error
    pig' = getPIGraph pig
    es' = map (edgePairs) (graphEdges pig')
    vs = map (Vertex . getPositive . vertexValue) (graphVertices pig')