module Code04GcdLcm where

remainder :: Integer -> Integer -> Integer
remainder n m = n - m * (div n m)

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


cds :: Integer -> Integer -> [Integer]
cds n m = [ f | f <- [1..min n m], n ? f && m ? f ]

-- gcd3 :: Integer -> Integer -> Integer
gcd3 n m = head [ c 
  | c <- cds n m
  , let k = cds n m
  , and [c ? k' | k' <- k ] ]