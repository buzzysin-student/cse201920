-- ! Q1 
-- * With Either, you can specify the type that you return on failure 

-- ! Q2
forget :: Either String a -> Maybe a
forget (Left  x) = Nothing
forget (Right x) = Just x

-- ! Q3
safeDiv' :: Int -> Int -> Either String Int
safeDiv' x y 
  | y == 0 = Left  "Indivisible"
  | y /= 0 = Right (div x y)

-- ! Q4
-- * Either () a /= Maybe a
-- * Left   ()   ?= Just ()
-- * Right   a   /= Nothing