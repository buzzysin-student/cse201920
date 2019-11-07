import Test.QuickCheck

-- ? What is Monad Type class? *
-- * Monad is a type class that includes
-- * IO

-- * For Test.QuickCheck, we use the Monad
-- * Gen, where Gen a != IO a 

-- ? Sampling *
-- * Running sample (arbitrary :: Gen Bool) will
-- * returns random members of the set of values in Bool

main = do 
  sample (arbitrary:: Gen (Either Bool (Maybe Int)))