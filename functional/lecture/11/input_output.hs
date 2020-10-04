currentDirectory :: String
currentDirectory = "./haskell/lecture/11/"

main = do
  -- writeFile (currentDirectory ++ "myFile.txt") "Hello, world!"
  putStrLn "Greetings! Welcome to Haskell! What is your name?"
  inputStr <- getLine
  putStrLn ("Nice to meet you, " ++ inputStr ++ "!")

-- ! Instructions can behave differently with the same input, whereas
-- ? Functions always return the same result with the same parameters

-- * Haskell functions are pure -> (?predictable)
-- * Haskell instructions are impure -> (! dangerous and unpredictable)