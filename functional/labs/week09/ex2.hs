import Test.QuickCheck

data Tree a = 
    Leaf a
  | Split (Tree a) (Tree a)
  deriving (Eq, Show)

-- * Ex2.1a
collapse :: Tree Int -> [Int]
collapse (Leaf a)    = [a]
collapse (Split a b) = collapse a ++ collapse b

-- * Ex2.2b
mirror :: Tree a -> Tree a
mirror (Split a b) = Split (mirror b) (mirror a)
mirror someLeaf    = someLeaf
