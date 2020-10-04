import Data.Char
import Test.QuickCheck

data Road a = City a | Fork (Road a) (Road a) 
  deriving Show
type Name = String

data Play = O | X 
  deriving (Eq, Show)

data NC = NC [[ Maybe Play ]]
  deriving Show

exampleNC :: NC 
exampleNC = NC [
    [Just O, Just X, Nothing],
    [Just X, Just O, Just X],
    [Nothing, Just X, Just O]
  ]

myCities :: Road Name
myCities = (Fork 
  (Fork
    (City "Bristol")
    (Fork 
      (City "Blackpool")
      (City "Burnley")))
  (Fork 
    (City "Bath") 
    (City "Birmingham"))
  )

myCitiesNames :: [Name]
myCitiesNames = ["Bristol", "Blackpool", "Burnley", "Bath", "Birmingham"]

myNewCitiesNames :: [Name]
myNewCitiesNames = ["Sheffield", "Southampton", "Stoke", "Salisbury", "Sudbury"]

-- ? 2a)
nameUpper :: Name -> Name
nameUpper = foldr ((:) . toUpper) ""

-- ? 2b)
size :: Road a -> Int
size (City c) = 1
size (Fork r1 r2) = (size r1) + (size r2)

-- ? 2c)
cities :: Road Name -> [Name]
cities (City c) = [c]
cities (Fork r1 r2) = (cities r1) ++ (cities r2)

-- ? 2d)
mapCities :: (a->b) -> Road a -> Road b
mapCities f (City c) = City (f c)
mapCities f (Fork r1 r2) = Fork r1' r2'
  where
    r1' = mapCities f r1
    r2' = mapCities f r2

-- ? 2e)
cityUpper :: Road Name -> Road Name
cityUpper = mapCities nameUpper

-- ? 2e)
rename :: Road Name -> [Name] -> Road Name
rename r [] = r
rename (City c) (n:ns) = City n
rename (Fork r1 r2) ns = Fork r1' r2'
  where
    n1 = take (size r1) ns
    n2 = drop (size r1) ns
    r1' = rename r1 n1
    r2' = rename r2 n2

{-
 * Testing
 -}

-- ? 2f)
prop_Something rd ns = size rd == length ns ==> cities (cityUpper rd) == ns
prop_SameSize rd ns = size rd == size (rename rd ns)

-- ? 3a)
-- ? 3a i)
newGrid :: Int -> NC
newGrid n = NC (take n (repeat (take n (repeat Nothing))))

-- ? 3a ii)
isNought :: Play -> Int
isNought O = 1
isNought _ = 0

-- ? 3a iii)
isEmpty :: Maybe Play -> Bool
isEmpty Nothing = True
isEmpty _ = False

-- ? 3a iv)
rowEmpty :: [Maybe Play] -> Bool
rowEmpty = foldr ((&&) . isEmpty) True

-- ? 3a v)
gridEmpty :: NC -> Bool
gridEmpty (NC grid) = foldr ((&&) . rowEmpty) True (grid)

-- ? 3a ??)
-- ! NOT DONE YET

-- ? 3a ??)
-- ! Cant test without previous
-- save :: FilePath -> NC -> IO ()
-- save name game = do
--   strGame <- return (toString game)
--   writeFile name strGame

-- ? 3b)
map' :: (a->b) -> [a] -> [b]
map' f = foldr ((:) . f) []