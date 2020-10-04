import Test.QuickCheck

-- ? Gen and IO are members of the same type class, Monad
-- ? The Arbitrary class has a function with the type
-- * arbitrary :: Gen a (it receives a generator of type a)

-- TODO: Warning - this does not work
evenInteger :: Gen Integer
evenInteger = do
  n <- arbitrary
  return (2 * n)

generateFrom1To10 :: IO ()
generateFrom1To10 = do
  sample (choose (1,10) :: Gen Integer)

generate1Or10 :: IO ()
generate1Or10 = do
  sample (oneof [return 1, return 10])