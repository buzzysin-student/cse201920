-- * Ex 2.c
insert :: Int -> [Int] -> [Int]
insert x []    = x : []
insert x (y:ys) 
  | x <  y     = x : y : ys
  | x >= y     = y : (insert x ys)

-- * Ex 2.d
isort :: [Int] -> [Int]
isort []     = []
isort (x:xs) = insert x (isort xs)

-- * Ex 2.e
-- ! Starred
merge :: [Int] -> [Int] -> [Int]
merge x y 
  | x == [] = isort y
  | y == [] = isort x
merge (x:xs) (y:ys) = isort (x : y : merge xs ys)

merge' :: [Int] -> [Int] -> [Int]
merge' x []       = x
merge' (x:xs) ys  = merge ys (insert x xs)

-- * Ex.f