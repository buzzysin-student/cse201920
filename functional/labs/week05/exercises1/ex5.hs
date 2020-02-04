import Prelude hiding ( 
    sum, product, and, or, 
    all, any, length, foldr, 
    foldl, reverse, lter, filter
  )

foldr :: (a->b->b) -> b -> [a] -> b
foldr op z [] = z
foldr op z (x:xs) = x `op` foldr op z xs

-- * Ex 5
filter :: (a -> Bool) -> [a] -> [a]
filter f xs = foldr g [] xs
  where g a b = if (f a) then a:b else b