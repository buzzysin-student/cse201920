import Prelude hiding ( 
    sum, product, and, or, 
    all, any, length, foldr, 
    foldl, reverse, lter, filter
  )

foldr :: (a->b->b) -> b -> [a] -> b
foldr op z [] = z
foldr op z (x:xs) = x `op` foldr op z xs

-- * Ex 7
-- transpose :: [[a]] -> [[a]]
-- transpose xs = 
--   let f xs [] = [ [el] | el <- xs ]
--       f (x:xs) (y:ys) = [ 
--         q 
--         | r <- [0..length ys]
--         , c <- [0..length y] 
--         ]
--   in foldr f [] xs

-- transpose [[1,2,3],[4,5,6]]
-- foldr f [] [[1,2,3], [4,5,6]]
-- [1,2,3] f foldr f [] [[4,5,6]]
-- [1,2,3] f [4,5,6] f foldr [] []
-- [1,2,3] f [4,5,6] f []
-- [[1,4],[2,5],[3,6]]