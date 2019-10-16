-- Q1
isJust :: Maybe a -> Bool
isJust (Just z) = True
isJust Nothing  = False

isJust' :: Maybe a -> Bool
isJust' ma = case ma of
  Just z  -> True
  Nothing -> False

-- Q2
isNothing = (not) . (isJust)

-- Q3
safeDiv :: Int -> Int -> Maybe Int
safeDiv x y 
  | y == 0 = Nothing
  | y /= 0 = Just (div x y)

-- Q4
fromMaybe :: a -> Maybe a -> a
fromMaybe a (Just b) = b
fromMaybe a Nothing  = a

-- Q5 
perform :: (Int -> Int) -> Maybe Int -> Maybe Int
perform f (Just x) = Just (f x)
perform f Nothing  = Nothing