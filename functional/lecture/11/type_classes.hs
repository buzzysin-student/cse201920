-- ? Type synonyms
type CharAndInt = (Char, Int)

ascii_a :: CharAndInt
ascii_a = ('A', 65)

-- ? Newtype declaration
newtype Metre = Metre Int
-- ! This is similar to data ... = ...
-- ! Metre is represented as an int, but
-- ! is a different to other tyoes
newtype Kilo = Kilo Int
-- ! For example, Kilo 1 + Metre 2 = ERROR!!!

-- ? Creating a type class
class Show' a where
  show' :: a -> String

-- ? Using instances of the type class
instance Show' Bool where
  show' True = "True"
  show' False = "False"

-- ? Other types can inherit existing definitions
data Suit =
  Diamonds | Hearts | Spades | Clubs
  -- * Inheritance happens here
  deriving Show

-- ? Classes form hierarchies - this class
-- ? inherits from Ord
-- class Eq a => Ord a where
  -- (<=) :: a -> a -> Bool
  -- compare :: a -> a -> Ordering