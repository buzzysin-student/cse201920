currentDirectory :: String
currentDirectory = "./haskell/lecture/11/"

copyFile :: FilePath -> FilePath -> IO()
copyFile source dest = do 
  contents <- readFile source
  writeFile dest contents


doTwice :: IO a -> IO (a,a)
doTwice io = do
  x <- io
  y <- io
  return (x,y)

dont :: IO a -> IO ()
dont io = do return ()

second :: [IO a] -> IO a
second (x:y:_) = y

-- sortFile :: FilePath -> FilePath -> IO ()
-- sortFile f1 f2 = do
--   s <- readFile f1
--   putStrLn (show (lines s))
--   writeFile f2 (unlines (sort (lines s)))

getLine' :: IO String
getLine' = do
  -- ? Get a character from input
  c <- getChar
  -- ? If there is a newline
  if c == '\n' then
    -- ? Stop receiving input
    undefined
  -- ? Otherwise recursively call getLine
  else do
    cs <- getLine'
    return (c:cs)