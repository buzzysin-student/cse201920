-- This receives two values and produces a VALUE
-- as an output.
add :: (Int, Int) -> Int
add (x,y) = x + y

-- This takes a value as input and returns a FUNCTION 
-- as an output
plus :: Int -> (Int -> Int)
plus x y = x + y

-- ORDER OF EVALUATION
-- plus 7 3:
-- => returns plus 7 y = 7 + y
-- => returns 7 + 3 = 10