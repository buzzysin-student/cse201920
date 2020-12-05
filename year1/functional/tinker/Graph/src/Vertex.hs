module Vertex where

import Test.QuickCheck

newtype Vertex v = Vertex v
  deriving (Show, Eq)

type VertexPair v = (Vertex v, Vertex v)

instance Arbitrary v => Arbitrary (Vertex v) where
  arbitrary = do Vertex <$> arbitrary

vertexValue :: Vertex v -> v
vertexValue (Vertex v) = v