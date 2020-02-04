import Prelude hiding ( 
    sum, product, and, or, 
    all, any, length, foldr, 
    foldl, reverse, lter
  )

foldr :: (a->b->b) -> b -> [a] -> b
foldr op z [] = z
foldr op z (x:xs) = x `op` foldr op z xs

-- * Ex 3a
sum :: [Integer] -> Integer
sum xs = foldr (+) 0 xs

-- * Ex 3b
product :: [Integer] -> Integer
product xs = foldr (*) 1 xs

-- * Ex 3c
-- ! Starred question
and :: [Bool] -> Bool
and xs = foldr (&&) True xs

-- * Ex 3d
or :: [Bool] -> Bool
or xs = foldr (||) False xs

-- * Ex 3e 
-- ! Starred question
all :: (a -> Bool) -> [a] -> Bool
all f xs = foldr ((&&) . f) False xs

-- all (\x -> x == 2) [2,2,3]
-- foldr ((&&) . (x == 2)) True [2,2,3]
-- (2 == 2) && foldr dotFn True [2,3]
-- (2 == 2) && (2 == 2) && foldr dotFn True [3]
-- (2 == 2) && (2 == 2) && (2 == 3) && foldr dotFn True []
-- (2 == 2) && (2 == 2) && (2 == 3) && True
-- False

-- * Ex 3f
any :: (a -> Bool) -> [a] -> Bool
any f xs = foldr ((||) . f) True xs

-- *  Ex 3g
length :: [a] -> Int
length xs = foldr cnt 0 xs
  where cnt _ b = b + 1

-- f current_value accumulator -
-- const (+1)
-- length [1,2,3]
-- foldr cnt 0 [1,2,3]
-- 1 `cnt _` foldr cnt [2,3]
-- 1 `cnt _` 2 `cnt _` foldr cnt 0 [3]
-- 1 `cnt _` 2 `cnt _` 3 `cnt _` foldr cnt 0 []
-- 1 `cnt _` 2 `cnt _` 3 `cnt _` 0
-- a `op` b == op a b