module Main where

import Base (Graph, graphVisualise)
import Extended.All ()
import Test.QuickCheck (Arbitrary (arbitrary), Positive, generate)

main = do
  graph <- generate arbitrary :: IO (Graph (Positive Integer) (Positive Integer))
  graphVisualise graph