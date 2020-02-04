-- ! LECTURE 5

import Test.QuickCheck

data Suit = Hearts | Diamonds | Clubs | Spades
  -- ? Eq allows that comparison of equivalence of members
  -- ? i.e. Hearts == Hearts := True
  deriving (Show, Eq)

data Colour = Black | Red
  deriving (Show, Eq)

data Rank = Numeric Int
  | Jack | King | Queen | Ace
  deriving (Show, Eq)

colour :: Suit -> Colour
colour Hearts   = Red
colour Diamonds = Red
colour Clubs    = Black
colour Spades   = Black

-- ! Pattern matching happens from the top
-- ! downwards, so the first case will be 
-- ! attempted, then the second, then the 
-- ! next, etc. until the last case.

-- ? Which card beats which?
rankBeats :: Rank -> Rank -> Bool

-- ! If the False/True statements were switched,
-- ! then the Ace would beat an Ace, for example, 
-- ! which does not indicate a tie.

-- ? `_` means `any input`

rankBeats _ Ace   = False
rankBeats Ace _   = True
rankBeats _ King  = False
rankBeats King _  = True
rankBeats _ Queen = False
rankBeats Queen _ = True
rankBeats _ Jack  = False
rankBeats Jack _  = True
rankBeats (Numeric m) (Numeric n) = m > n

-- ? Run a check for ranks beating each other
prop_checkRank a b = 
  -- ? This means -> only run this check when
  -- ? a and b are not the same card
  a /= b ==> 
    -- ! This alone was not enough to check
    -- ! that at least one card can win. This
    -- ! fails when the cards are equal. See
    -- ! above for the solution
    rankBeats a b || rankBeats b a

-- * A card has a Rank and a Suit
data Card = Card Rank Suit
  deriving Show

-- * Inspect the card
rank :: Card -> Rank
rank (Card r s) = r

suit :: Card -> Suit
suit (Card r s) = s

cardBeats :: Card -> Card -> Bool
cardBeats (Card r s) (Card r' s') = 
  -- * When cards have the same suit 
  s == s' &&
  -- * and the rank is higher
  rankBeats r r'

data Hand = Empty | Add Card Hand
  -- * Adds constructors
  -- ? Empty :: Hand
  -- ? Add :: Card -> Hand -> Hand
  deriving Show

-- * How many cards in the hand? 
size :: Hand -> Int
-- * If the hand is empty, return 0
size Empty            = 0
-- * If the hand has cards, count the card and the rest of the hand
size (Add card hand)  = 1 + size hand

-- ? See whether a hand can beat a card
handBeats :: Hand -> Card -> Bool
handBeats Empty card = 
  -- * An empty hand can't beat anything
  False 
handBeats (Add c h) card = 
  -- * A hand beats a card if the first card or if any 
  -- * of the other cards can
  cardBeats c card || handBeats h card

-- ? c = card to beat, c' card in my hand
chooseCard :: Card -> Hand -> Card
chooseCard c (Add c' Empty) = c'
chooseCard c (Add c' h) 
  -- * Choose your current card if it beats the other card
  | cardBeats c' c = c'
  -- * Otherwise check if the hand can beat the other card
  | otherwise      = chooseCard c h

prop_checkCardSelection card hand = 
  -- * The test passes if card picked is beated by the hand...
  handBeats hand card == 
  -- * ... and the chosen card beats the hand
  cardBeats (chooseCard card hand) card