module Operators where
  
infixr 5 +>

infixr 5 +^

infixr 5 .^

-- analogue is (:)
(+>) :: Eq n => n -> [n] -> [n]
(+>) n ns
  | n `elem` ns = ns
  | otherwise = n : ns

-- C = forall A,B: c : c in A or c in B, but c does not repeat
(+^) :: Eq n => [n] -> [n] -> [n]
(+^) ns ms = foldr (+>) [] (ns ++ ms)

-- C = forall A,B: c : c in A and B, but c does not repeat
(.^) :: Eq n => [n] -> [n] -> [n]
(.^) ns ms = filter (`elem` ms) ns

setify :: (Foldable t, Eq n) => t n -> [n]
setify = foldr (+>) []

newtype Flow f = Flow (f, f)

