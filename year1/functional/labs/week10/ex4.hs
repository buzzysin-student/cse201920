-- * Ex4.1
-- ! Starred question

-- * Just x >>= return
-- * return (Just x)
-- * Just x (= RHS)
-- ? Nothing >>= return
-- ? return (Nothing)
-- ? Nothing (=RHS)

-- * return (Just x) >>= f
-- * f (return (Just x))
-- * f (Just x) = (RHS)
-- ? return (Nothing) >>= f
-- ? f (return Nothing)
-- ? f Nothing (=RHS)

-- * (Just x) >>= f >>= g
-- * f (Just x) >>= g
-- * g (f (Just x))
-- * (\y -> g (f y)) (Just x) 
-- * (Just x) >>= (\y -> g (f y))
-- * (Just x) >>= (\y -> f y >>= g) (=RHS)
-- ? (Nothing) >>= f >>= g
-- ? f (Nothing) >>= g
-- ? g (f (Nothing))
-- ? (\y -> g (f y)) (Nothing) 
-- ? (Nothing) >>= (\y -> g (f y))
-- ? (Nothing) >>= (\y -> f y >>= g) (=RHS)

-- * Ex4.3
-- ! Starred question

part1 mx = do
  x <- mx
  return x
part1' mx = 
  mx >>= \x ->
  return x -- = mx
-- * Left unit law

part2 x = do  
  x <- return y
  f y
part2' f x = 
  x >>= \y ->
  f y -- = f x
-- * Right unit law

part3 mx f g = do
  x <- mx 
  do
    y <- mx
    g y
part3' mx f g = 
  mx  >>= \x ->
  f x >>= \y ->
  g y -- = g (f x)

