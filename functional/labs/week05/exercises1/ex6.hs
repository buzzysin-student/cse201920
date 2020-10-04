import Prelude hiding ( 
    sum, product, and, or, 
    all, any, length, foldr, 
    foldl, reverse, lter, filter
  )

foldr :: (a->b->b) -> b -> [a] -> b
foldr op z [] = z
foldr op z (x:xs) = x `op` foldr op z xs

-- * Ex 6
group :: (Eq a) => [a] -> [[a]]
group xs =
  let f y' [] = [[y']]
      f y' ((y:ys):yss)
        | y == y' = ((y':y:ys):yss)
        | y /= y' = ([y']:(y:ys):yss)
  in foldr (f) [] xs


-- 1 f 2 f 2 f 3 f 3 f 3 f 4 f []
-- 1 f 2 f 2 f 3 f 3 f 3 f [[4]]
-- 1 f 2 f 2 f 3 f 3 f [[3], [4]]
-- 1 f 2 f 2 f 3 f [[3,3], [4]]
-- 1 f 2 f 2 f [[3,3,3], [4]]
-- 1 f 2 f [[2], [3,3,3], [4]]
-- 1 f [[2,2], [3,3,3], [4]]
-- [[1], [2,2], [3,3,3], [4]]

-- [[1,2], [3,4]]
-- ((y:ys):yss) -> y = 1, ys = [2], yss = [[3,4]]