data Suit = Spades | Hearts | Diamonds | Clubs
  deriving (Show, Eq)
data Rank = Numeric Int | King | Queen | Jack | Ace
  deriving (Show, Eq)
data Card c s = Suit Rank
  deriving (Show, Eq)
  
