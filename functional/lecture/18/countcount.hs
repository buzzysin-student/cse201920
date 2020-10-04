f :: Int -> Int -> (Int, Int)
f y calls
  | y <= 0 = (1, calls + 1)
  | y >  0 = (y * result, calls')
  where (result, calls') = f (y - 1) (calls + 1)

f' :: Int -> Int
f' y 
  | y <= 0 = 1
  | y >  0 = y * f' (y - 1)

main :: IO ()
main = do
  let calls = 0
  let (n, calls') = f 4 calls
  putStrLn ("Total is " ++ show n ++ " after " ++ show calls' ++ " calls")

pair :: a1 -> a2 -> (a1,a2)
pair a1 a2 = (a1, a2)

unpair :: (a1, a2) -> Int -> Either a1 a2
unpair (a1,a2) 0 = Left  a1
unpair (a1,a2) 1 = Right a2

type ProgramState = Int
