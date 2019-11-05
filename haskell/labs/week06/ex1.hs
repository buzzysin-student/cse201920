-- ? Ex 1.1a
nats :: [Integer]
nats = [1..]

squares :: [Integer]
squares = [ i * i | i <- nats ]

-- ? Ex 1.1b
map' :: (a->b) -> [a] -> [b]
map' f xs = [ f x | x <- xs ]

-- ? Ex 1.1c
filter' :: (a->Bool) -> [a] -> [a]
filter' f xs = [ x | x <- xs, f x ]

-- ? Ex 1.1d
-- ! Starred question
cartesian :: [a] -> [b] -> [(a,b)]
cartesian xs ys = [ (x,y) | x <- xs, y <- ys ]

-- ? Ex 1.2a
-- bitString :: Int -> [String]
-- bitString n = [ b,  ]