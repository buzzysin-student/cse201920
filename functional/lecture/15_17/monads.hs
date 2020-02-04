-- * Managing monands and syntactic sugar

-- * Syntactic sugar:
-- ? do {e}                       ==> e
-- ? do { e; statements }         ==> e >> do { statements }
-- ? do { x <- e; statments }     ==> e >>= (\x -> do { statements }) 
-- ? do { let x = e; statements } ==> do { statements } where x = e

-- ! Type signatures:
class Monad m where 
  -- ? Converts a type to an instruction
  return' :: a -> m a
  -- ! Name: BIND (>>=)
  -- ? Transforms the output of an instruction
  -- ? using a function
  (>>-) :: m a -> (a -> m b) -> m b
  -- ! Name: (>>)
  (>-) :: m a -> m b -> m b

-- ! MONAD LAWS

-- ! LEFT UNIT LAW
leftUnitLaw f x = (return x >>= f) == f x
-- ! RIGHT UNIT LAW
rightUnitLaw mx = (mx >>= return) == mx
-- ! ASSOCIATIVE LAW
associativeLaw mx f g = ((mx >>= f) >>= g) == (mx >>= (\x -> f x >>= g))



main = (>>=) 
  (putStrLn "Hello") 
  (return (do putStrLn "World"))
  
main' = do  
  putStrLn "Hello"
  putStrLn "World"