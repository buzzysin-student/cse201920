import Test.QuickCheck

data Expr = 
    Num Int
  | Add Expr Expr
  | Mul Expr Expr
  | Sub Expr Expr
  | Div Expr Expr

-- * Ex 1.1a
size :: Expr -> Int
size (Add e1 e2) = 1 + size(e1) + size (e2)
size (Mul e1 e2) = 1 + size(e1) + size (e2)
size (Sub e1 e2) = 1 + size(e1) + size (e2)
size (Div e1 e2) = 1 + size(e1) + size (e2)
size (Num n)     = 0

-- * Ex 1.1b
-- ! Starred question
instance Show Expr where
  -- * Simple cases
  show (Add e1 e2) = (show e1) ++ " + " ++ (show e2)
  show (Sub e1 e2) = (show e1) ++ " - " ++ (show e2)
  -- * Factor cases (Multiplication)
  show (Mul e1 (Add e2 e3)) = (show e1) ++ " * (" ++ (show e2) ++ ")"
  show (Mul e1 (Sub e2 e3)) = (show e1) ++ " * (" ++ (show e2) ++ ")"
  show (Mul e1 e2) = (show e1) ++ " * " ++ (show e2)
  -- * Factor cases (Division)
  show (Div e1 (Add e2 e3)) = (show e1) ++ " / (" ++ (show e2) ++ ")"
  show (Div e1 (Sub e2 e3)) = (show e1) ++ " / (" ++ (show e2) ++ ")"
  show (Div e1 e2) = (show e1) ++ " / " ++ (show e2)

  show (Num n)     =  show n

eval :: Expr -> Int
eval (Add e1 e2) = (+) (eval e1) (eval e2)
eval (Mul e1 e2) = (*) (eval e1) (eval e2)
eval (Sub e1 e2) = (-) (eval e1) (eval e2)
eval (Div e1 e2) = div (eval e1) (eval e2)
eval (Num n)     = n


safeEval :: Expr -> Maybe Int
safeEval (Div e1 (Num 0)) = Nothing
safeEval (Div e1 e2)      = Just (eval (Div e1 e2))
safeEval expr             = Just (eval expr)

instance Arbitrary Expr where
  arbitrary = frequency [
      (1, do
        n <- choose (0,10)
        return (Num n)
        ),
      (1, do
        e1 <- arbitrary
        e2 <- arbitrary
        op <- frequency [
          (3,return Add), 
          (2,return Sub),
          (1,return Mul), 
          (1,return Div)]
        return (op e1 e2)
        )
    ]