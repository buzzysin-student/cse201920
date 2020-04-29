remainder :: Integer -> Integer -> Integer
remainder n m = n - m * (div n m)

mcd :: Integer -> Integer -> Integer 
mcd n m 
  | n < m     = flip mcd n m
  | otherwise = _mcd n m (remainder n m)
  where
    _mcd :: Integer -> Integer -> Integer -> Integer
    _mcd p q r 
      | remainder p q == 0 = q 
      | otherwise          = _mcd q r (remainder q r)

scm :: Integer -> Integer -> Integer
scm n m = div (n * m) (mcd n m)

coprime :: Integer -> Integer -> Bool
coprime n m = mcd n m == 1

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