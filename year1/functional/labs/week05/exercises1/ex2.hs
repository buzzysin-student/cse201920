import Prelude hiding ( 
  sum, product, and, or, 
  all, any, length, foldr, 
  foldl, reverse, lter
)

-- * Ex 2a
foldr :: (a->b->b) -> b -> [a] -> b
foldr op z [] = z
foldr op z (x:xs) = x `op` foldr op z xs

