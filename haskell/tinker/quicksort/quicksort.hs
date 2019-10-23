getElement :: Int -> [Int] -> Int
getElement _ []     = -1
getElement 0 (x:xs) = x
getElement i (x:xs) = getElement (i-1) xs

getPivotIndex :: [Int] -> Int
getPivotIndex xs = (div (length xs) 2)

getPivot :: [Int] -> Int
getPivot xs 
  | length xs <= 1    = getElement 0 xs
  | otherwise         = getElement (getPivotIndex xs) xs

quicksort :: [Int] -> [Int]
quicksort xs 
  | length xs <= 1 = xs
  | otherwise =
    quicksort [
      el |
      -- * where j is the index of the element
      j <- [0..(length xs) - 1],
      -- * find the element at index j
      let el = getElement j xs, 
      -- * and j is not the the index of p
      j /= (getPivotIndex xs),
      -- * and i is less than or equal to p
      el <= (getPivot xs)
    ]
      ++
    [
      -- * List containing p only
      getPivot xs
    ]
      ++ 
    quicksort [
      el |
      -- * where j is the index of the element
      j <- [0..(length xs) - 1],
      -- * find the element at index j
      let el = getElement j xs, 
      -- * and j is not the the index of p
      j /= (getPivotIndex xs),
      -- * and i is less than p
      el > (getPivot xs)
    ]

map :: (a -> b) -> [a] -> [b]
map f xs = [f i | i <- xs]