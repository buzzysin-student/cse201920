square n = n * n
two n = 2

{-
 ? This is a long way to combine functions
 -}
twoSquare n = two (square n)
squareTwo n = square (two n)

{- 
 ! Here is a better way 
 TODO: dot operator 
 -}