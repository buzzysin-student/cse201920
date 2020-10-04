-- ? Take a line from a string containing newlines
takeLine :: String -> String
takeLine [] = []
takeLine (x:xs) 
  | x /= '\n' = x : takeLine xs
  | otherwise = []

-- * To generalise - general case of taking from a list
takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' p [] = []
takeWhile' p (x:xs) 
  | p x = x : takeWhile' p xs
  | otherwise = []

-- * New definition of takeLine
takeLine' :: String -> String
takeLine' = takeWhile' (/='\n')

-- * Split a string into a list based on \n
lines' :: String -> [String]
lines' [] = []
lines' xs = takeWhile (/='\n') xs : lines' (
    drop 1 (dropWhile (/='\n') xs)
  )

-- * Generalising lines
segments :: (a->Bool) -> [a] -> [[a]]
segments p [] = []
segments p xs = takeWhile' p xs : segments p (
    drop 1 (dropWhile p xs)
  )

countWords :: String -> String
countWords 
  = unlines
  . map (\ws -> head ws ++":"++show (length ws))
  . groupBy (==)
  . sort
  . words