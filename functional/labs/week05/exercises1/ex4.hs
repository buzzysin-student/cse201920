import Prelude hiding ( 
    sum, product, and, or, 
    all, any, length, foldr, 
    foldl, reverse, lter
  )

foldr :: (a->b->b) -> b -> [a] -> b
foldr op z [] = z
foldr op z (x:xs) = x `op` foldr op z xs

-- * Ex 4
reverse :: [a] -> [a]
reverse xs = foldr snoc [] xs
  where snoc y ys = ys ++ [y]

-- reverse [1,2,3]
-- foldr snoc [] [1,2,3]
-- 1 snoc foldr snoc [] [2,3]
-- 1 snoc 2 snoc foldr snoc [] [3]
-- 1 snoc 2 snoc 3 snoc foldr snoc [] []
-- 1 snoc 2 snoc 3 snoc []
-- 1 snoc 2 snoc [3]
-- 1 snoc [3,2]
-- [3,2,1]