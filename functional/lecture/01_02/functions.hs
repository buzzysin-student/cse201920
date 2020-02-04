{- 
 ? Maths:   f    (x)         = x^2
 ?          name     (param) = definition
 ! Haskell: square x :: Int -> Int
 !          square x         = x * x
 !          name   param     = definition
 * Every function in Haskell has One Input Type
 * and One Output Type
 -}

-- The type of square is Int -> Int (input Int, output Int)
square :: Int -> Int
square x = x * x

-- Functions can ignore input parameters
-- This is called a NON-STRICT FUNCTION
two :: Int -> Int -- This function WILL NOT WORK WITHOUT INPUT
two n = 2
-- two # <- This will not work
two 1 -- Will always give 2, but requires input
two undefined -- Will STILL give 2

-- Function Combination
square (two 5) -- calls two 5, then calls square (2), which evaluates to 4