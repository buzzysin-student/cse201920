-- * Ex 1.1
-- class Monad m where
--   return  :: a ->   (m a)
--   (>>)    :: m a ->  m b -> m b
--   (>>=)   :: m a -> (  a -> m b) -> m b 

-- * Ex 1.2
-- ! Starred question
ap :: Monad m => m (a->b) -> m a -> m b
ap mf mx = do 
  f <- mf
  x <- mx
  return (f x)

ap' :: Monad m => m (a->b) -> m a -> m b
ap' mf mx = 
  mf >>= \f -> 
  mx >>= \x -> 
  return (f x)

