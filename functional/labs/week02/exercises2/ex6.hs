{-
  * A) Give the types of takeAway and subtract
 -}

takeAway :: (Int, Int) -> Int -- Answer
takeAway (x,y) = y - x

_subtract :: Int -> (Int -> Int) -- Answer
_subtract x y = y - x

{-
 * B) Redefine subtract in terms of takeAway
 -}

_subtract x y = takeAway(x,y)

{-
 * C) Find the error
 -}

apply :: (a -> b) {- f -} -> a {- x -} -> b {- Output -}
apply f x = f x

_curry :: ((a->b)->c) -> ((a,b)->c)
_curry f x y = f (x,y)

curryToGo = _curry takeAway

-- apply (takeAway 3) 1 -- doesn't work
-- apply (subtract 3) 1 -- works

