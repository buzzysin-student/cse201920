module Extended.Vertex where

import Test.QuickCheck
  ( Arbitrary (arbitrary),
    Positive (getPositive),
  )
import Vertex (Vertex (..), vertexValue)

newtype PIVertex = PIVertex {getPIVertex :: Vertex (Positive Integer)}

pivNormalise :: PIVertex -> Vertex Integer
pivNormalise piv = Vertex (getPositive (vertexValue (getPIVertex piv)))

instance Arbitrary PIVertex where
  arbitrary = do PIVertex <$> arbitrary
