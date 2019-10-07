{-
 ? In Haskell, types are represented by
 ? sets that they are a part of. Void is
 ? part of the empty set. Unit type represents
 ? the set with 1 element

 ? Number types  -> 5 :: Integer
 ?               -> 5 :: Float
 ! Boolean type  -> True :: Bool
 !               -> False :: Bool
 * Text-based    -> 'a' :: Char
 *               -> "abc" :: String
 ? Void type     -> undefined :: a # This type represent nothing (anti-set)
 ?               -> In this case, `undefined` can be ANY type
 ! Unit type     -> () :: ()
 -}

-- It is possible to define custom types
data Day = 
    Monday | Tuesday |
    Wednesday | Thursday |
    Friday | Saturday |
    Sunday
-- This introduces 'constructors'

-- Types can be added together
data Either a b = Left a | Right b
-- This has introduced two constructors:

-- > Left  :: a -> Either a b
-- > Right :: b -> Either a b

-- Example Type Addition

{- 
 ! TODO: Type addition examples 
 -}

-- Types can be multiplied together
data (a,b) = (a,b)
-- The type (a,b) is called the `pair` type
-- the parameters a and b are arbitrary

-- The input parameter order does matter, but the 
-- output can be anything that is desired

-- Example type multiplication

{- 
 ! TODO: Type mutiplication examples 
 -}
