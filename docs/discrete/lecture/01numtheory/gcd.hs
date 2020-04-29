remainder :: Integer -> Integer -> Integer
remainder n m = n - m * (div n m)

infixr 5 ?
(?) :: Integer -> Integer -> Bool
n ? m = remainder n m == 0

gcd2 :: Integer -> Integer -> Integer 
gcd2 n m 
  | n < m     = flip gcd2 n m
  | otherwise = _gcd2 n m (remainder n m)
  where
    _gcd2 :: Integer -> Integer -> Integer -> Integer
    _gcd2 p q r 
      | p ? q              = q 
      | otherwise          = _gcd2 q r (remainder q r)

lcm2 :: Integer -> Integer -> Integer
lcm2 n m = div (n * m) (gcd2 n m)

coprime :: Integer -> Integer -> Bool
coprime n m = gcd2 n m == 1

primes :: Integer -> [Integer]
primes n = _primes n 2 []
  where 
    _primes n p ps 
      | p > n                                      = ps
      | foldr ((&&).(coprime p)) True ps == False  = _primes n (p + 1)  ps
      | otherwise                                  = _primes n (p + 1) (ps ++ [p])

prime :: Integer -> Bool
prime n = elem n $ primes n

composite :: Integer -> Bool
composite = not . prime

cds :: Integer -> Integer -> [Integer]
cds n m = [ f | f <- [1..min n m], n ? f && m ? f ]

-- gcd3 :: Integer -> Integer -> Integer
gcd3 n m = [ c 
  | c <- cds n m
  , let k = cds n m
  , and [c ? k' | k' <- k ] ]