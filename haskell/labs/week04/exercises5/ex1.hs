data List a = Empty | Cons a (List a)
  deriving (Show, Eq)

toList :: [a] -> List a
toList []     = Empty
toList (x:xs) = Cons x (toList xs)