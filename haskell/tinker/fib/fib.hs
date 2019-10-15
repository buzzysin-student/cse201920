fib :: Int -> Int
fib 1 = 0
fib 2 = 1
fib n = fib (n - 1) + fib (n - 2)

myInt :: Int
myInt = 2

fib2 :: Int -> Int
fib2 n = 
  floor
  (
    (((0.5) * (1 + sqrt 5)) ^ n) / (sqrt 5)
  )