import Data.Char

data Expr = 
    Num Int 
  | Add Expr Expr 
  | Mul Expr Expr 

type Parser a = Maybe (a, String)

number :: String -> Parser Int
number (c:s) 
  | isDigit c = Just (digits 0 (c:s))
number _  = Nothing

digits :: Int -> String -> (Int, String)
digits n (c:s) 
  | isDigit c = digits (10*n + digitToInt c) s
digits n s     = (n,s)

num :: String -> Parser Expr
num s = case number s of
  Just (n, s1)  -> Just (Num n, s1)
  Nothing       -> Nothing

-- expr :: Maybe (Int, String) -> Parser Int
-- expr s1 = case num s1 of 
--     Just (n1, s2) -> case s2 of 
--       "+":s3 -> case expr s3 of 
--         Just (n2, s4) -> Just (Add n1 n2, s4)
--         Nothing       -> Just (n1, s2)
--       _      -> Just (n1, s2) 
--     Nothing  -> Nothing