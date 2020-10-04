-- * Ex 1.1
helloWorld :: IO ()
helloWorld = putStrLn "Hello, World!"

-- * Ex 1.2
sayHello :: String -> String
sayHello name = ("Hello, " ++ name)

-- * Ex 1.3
greet :: IO ()
greet = do 
  name <- getLine
  putStrLn (sayHello name)
  
-- * Ex 1.4
-- ! Starred Question
greet' :: IO ()
greet' = do
  putStr "What is your name?: "
  greet

-- * Ex 1.5
getInt :: IO Int
getInt = do
  int <- getLine
  return (read int)
