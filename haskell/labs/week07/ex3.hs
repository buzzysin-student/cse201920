-- ? Helper function

-- * Ex 1.5
getInt :: IO Int
getInt = do
  int <- getLine
  return (read int)

determine :: Int -> Int -> (Int -> IO ()) -> IO ()
determine x y f 
  | (x <  y) = do 
    putStrLn "Too large! Try again"
    f x
  | (x >  y) = do 
    putStrLn "Too small! Try again" 
    f x
  | otherwise = do 
    putStrLn "You win!"

-- * Ex3.1
playRound :: Int -> IO ()
playRound x = do 
  putStr "Please guess the number: "
  y <- getInt
  determine x y playRound
  
      