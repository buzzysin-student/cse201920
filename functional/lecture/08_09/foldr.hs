-- ? Foldr can be used to create recursive functions and is reusable

foldr' :: (a -> b -> b) -> b -> [a] -> b
foldr' op z []      = z
foldr' op z (x:xs)  = op (x) (foldr' op z xs)

-- ! You can define other functions with foldr

sum' :: [Int] -> Int
sum' xs = foldr (+) 0 xs

fac' :: Int -> Int
fac' n = foldr (*) 1 [1..n]

filter' :: (a -> Bool) -> [a] -> [a]
filter' f (x:xs) = foldr f x xs