import Test.QuickCheck

-- * We can represent arithmetic expressions using data types
data Expr = 
  -- * e.g. 3
    Num Int
  -- * e.g. 3 + 3
  | Add Expr Expr
  -- * e.g. 3 * 3
  | Mul Expr Expr

-- * Expression must be able to be evaluated
exprEval :: Expr -> Int
exprEval (Num n) = n
exprEval (Add a b) = exprEval a + exprEval b
exprEval (Mul a b) = exprEval a * exprEval b

exprShow :: Expr -> String
exprShow (Num n) = show n
exprShow (Add a b) = exprShow a ++ "+" ++ exprShow b
exprShow (Mul a b) = exprShowFactor a ++ "*" ++ exprShowFactor b
-- exprShow (Mul a (Add x y)) = exprShow a ++ "*" ++ "(" ++ exprShow (Add x y) ++ ")"
-- exprShow (Mul (Add x y) b) = "(" ++ exprShow (Add x y) ++ ")" ++ "*" ++ exprShow b

exprShowFactor :: Expr -> String
exprShowFactor (Add a b) = "(" ++ exprShow (Add a b) ++ ")"
exprShowFactor _         = exprShow _

instance Show Expr where
  show = exprShow

exprArbitrary :: Gen Expr
exprArbitrary s = 
  frequency 
    [
      (1, do 
        n <- arbitrary
        return (Num n)),
      (s, do 
        a <- exprArbitrary s'
        b <- exprArbitrary s'
        return (Add a b)),
      (s, do
        a <- exprArbitrary s'
        b <- exprArbitrary s'
        return (Mul a b))
    ]
  where s = s `div` 2


instance Arbitrary Expr where
  arbitrary = exprArbitrary