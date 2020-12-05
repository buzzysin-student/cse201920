module Extended.Edge where

import Edge (Edge (..), edgePairs, edgeValue)
import Test.QuickCheck
  ( Arbitrary (arbitrary),
    Positive (getPositive),
  )
import Vertex ()

newtype PIEdge v = PIEdge {getPIEdge :: Edge (Positive Integer) v}

pieNormalise :: PIEdge v -> Edge Integer v
pieNormalise pie = Edge (getPositive (edgeValue pie')) v
  where
    pie' = getPIEdge pie
    v = edgePairs pie'

instance (Arbitrary e, Arbitrary vs) => Arbitrary (Edge e vs) where
  arbitrary = do
    e <- arbitrary
    Edge e <$> arbitrary
