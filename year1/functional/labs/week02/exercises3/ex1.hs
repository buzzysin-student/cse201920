const :: a -> b -> a
const k x = k

twice :: (a -> a) -> (a -> a)
twice f x = f (f x)

infinity :: Integer
infinity = 1 + infinity
