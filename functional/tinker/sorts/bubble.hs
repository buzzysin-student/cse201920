bubble :: [Int] -> Bool -> [Int]
bubble []   _              = []
bubble [x]  _              = [x]
bubble (x1:x2:xs) s
  | x1 >  x2              = bubble (x2 : x1 : xs) True
  | x2 >= x1 && s == True = bubble (x1 : bubble (x2 : xs) False) False
  | x2 >= x1 && s /= True = x1 : x2 : xs

-- test :: [Int] -> (Int, Int)
-- test (x1:x2:xs) = (x1, x2)