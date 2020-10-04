-- My first Haskell Program! Whoop Whoop!
-- Here are some ?necessary imports

import Data.List
import System.IO

main = putStrLn "Hello World!"

{- 
 * I am now exploring multi-line comments. Nice.
 -}

-- Let's employ some data structures.

{- 
 * Int type 
 ? Overflows at -2^[*someMaxPower] or 2^[*someMaxPower]
 ? *someMaxPower = system-specific 
 -}
myInt = 3 

{-
 * Integer type 
 ? Does not overflow 
 * Most commonly used over Int
-}
myInteger = 2 ^ 63 

{-
 * Float type
 ! Has less precision than a Double type
 -}
myFloat = 2.7182818

{- 
 * Double type
 ? Has more precision than a Float type (10 d.p.)
 * Most commonly used over float
 -}
myDouble = 2.7182818285

{-
 * Bool type
 ? Just the standard hoohah of true/false
 -}
myBool = True || False

{-
 * Char type
 ? Single character (i.e. 's')
 ! Denoted by single quotes! ''
 -}
myChar = 'c'

{-
 * String type
 ? Finite sequence of characters
 ! Denoted by double quotes! ""
 -}

{-
 * List type
 ! A list must contain the same type for all its members
 ? A list is a sequence of values all of the same type ?signature 
 -}
myList = [1,2,3] -- A list containing Int (or Integer) types

{-
 * Tuple type
 ? A tuple is **like** a list that can contain different types
 -}
myTuple = (2, 2.5, 2.5102983, False, '?', [4,5,6])

-- Let's create an immutable variable
myConst :: Double
myConst = 3.14159265359 -- PI never changes

-- List generators
oneToHundred = [1..100]

-- Mathematical operations

numAdd = 7 + 2
numSub = 7 - 2
numMul = 7 * 2
numDiv = 7 / 2
numMod = mod 7 2 -- mod is a 'prefix operator'
numMd2 = 7 `mod` 2 -- identical to mod 7 2

-- Type casting and type changes
{- Example
 - =======
 ? Haskell cannot do `sqrt` with integers. 
 ? The number in question must be converted
 ? to a floating point number (?or double)
 ? in order for this to work
 -}

-- 9 is type-casted to an integer
-- which the `sqrt` function cannot
-- deal with
numToSqrt :: Int
numToSqrt = 9
-- Let's create a number that we can
-- use `sqrt` on - a floating decimal
sqrtableN = fromIntegral numToSqrt -- This is a type-cast from Int to Floating
sqrted = sqrt (sqrtableN) -- 3.0 (notice the trailing zero)