import Prelude hiding ( 
  sum, product, and, or, 
  all, any, length, foldr, 
  foldl, reverse, lter
)


-- * Ex 1a
-- ? Add numbers in a list
sum :: [Int] -> Int
sum [] = 0
sum (x:xs) = x + sum xs

-- sum 1:2:3:[]
-- 1 + sum 2:3:[]
-- 1 + 2 + sum 3:[]
-- 1 + 2 + 3 + sum []
-- 1 + 2 + 3 + 0

-- * Ex 1b
-- ? Continued product of items in a list
product :: [Int] -> Int
product [] = 1
product (x:xs) = x * product xs