module Code05Primes where

import Code04GcdLcm ( coprime )

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