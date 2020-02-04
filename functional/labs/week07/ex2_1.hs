import System.Environment

-- * Ex2.1a
echoArgs :: IO ()
echoArgs = do
  args <- getArgs
  -- * Ex2.1c
  -- print args
  print (unwords args)

-- * Ex2.1b
main :: IO ()
main = echoArgs
