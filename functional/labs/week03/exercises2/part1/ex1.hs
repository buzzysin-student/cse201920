delta :: Int -> Int
delta t 
  | t == 0 = 1
  | t /= 0 = 0

myDirac :: Int -> (Int -> Int)
myDirac n = (delta) . (subtract n)

dirac :: Int -> Int -> Int
dirac n t = delta (t - n)

check :: Bool -> [Char]
check exp 
  | exp == True    = "True"
  | exp /= False   = "False"

main = do
  putStrLn (check ( (dirac 1 0) == (myDirac 1 0) ) )
  putStrLn (check ( (dirac 1 1) == (myDirac 1 1) ) )
  putStrLn (check ( (dirac 0 1) == (myDirac 0 1) ) )
  putStrLn (check ( (dirac 0 0) == (myDirac 0 0) ) )
  putStrLn (check ( (dirac 2 4) == (myDirac 2 4) ) )
  putStrLn (check ( (dirac 4 2) == (myDirac 4 2) ) )
