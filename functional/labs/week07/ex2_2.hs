import System.Environment

pwd :: FilePath
pwd = "./haskell/labs/week07/"

-- * Ex2.2a
addLineStart :: [String] -> [String]
addLineStart = map ("> "++)

-- * Ex2.2b
addLineStartToFile :: String -> String
addLineStartToFile = 
    unlines 
  . addLineStart
  . lines

-- * Ex2.2c, Ex2.2d, Ex2.2e
-- ! Starred question
hsToLhs :: String -> String -> IO ()
hsToLhs infile outfile = do
  source <- readFile infile
  writeFile outfile (addLineStartToFile source)

main :: IO ()
main = do
  args <- getArgs
  hsToLhs (args !! 0) (args !! 1)