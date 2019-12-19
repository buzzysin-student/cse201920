-- * Ex3.1
map1 :: (a->b) -> [a] -> [b]
map1 f as = 
  (return f)  >>= \f'  ->
  (return as) >>= \as' ->
  map f as

map2 f as = do
  f'  <- (return f)
  as' <- (return as)
  map f as

-- * Ex3.2
-- ! Starred question
concat1 :: [[t]] -> [t]
concat1 []  = []
concat1 (xs:xss) =
  (return xss) >>= \xss' ->
  xs ++ concat1(xss)