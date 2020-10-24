data Request t = Request (t, t)
  deriving (Show, Eq)

instance Ord t => Ord (Request t) where
  compare (Request (s,f)) (Request (s', f'))
    | f == f'   = compare s s' -- ? Sort by end time, not start time
    | otherwise = compare f f'

compatible (Request (s,f)) (Request (s',f')) = s >= f' || s' >= f

-- ? Basically just quicksort
order []    = []
order [rq]  = [rq]
order rqs   = (order lts) ++ [pvt] ++ (order gts)
  where
    ignore i xs   = (take i xs) ++ (drop (i+1) xs)
    pvtIndex      = div (length rqs) 2
    remaining     = ignore pvtIndex rqs
    pvt           = rqs !! pvtIndex
    lts           = filter (\rq -> rq <  pvt) remaining
    gts           = filter (\rq -> rq >= pvt) remaining

ordered _ [] = True
ordered _ [x] = True
ordered cmp (x:y:xs) = (compare x y == cmp || compare x y == EQ) && ordered cmp (y:xs)

requests = [
      Request (0,30)
    , Request (5, 20)
    , Request (15, 55)
    , Request (20, 25)
    , Request (25, 40)
    , Request (38, 50)
    , Request (45, 60)
  ]

-- ? The real algorithm starts here

greedySchedule []  = []
greedySchedule rqs
  | not $ ordered LT rqs  = greedySchedule $ order rqs -- ? Order requests by end time once
  | otherwise             = rq : greedySchedule rest
    where
      rq    = head rqs -- ? Get earliest finishing compatible request
      rest  = filter (compatible rq) rqs -- ? Ignore incompatible requests


-- -- Result
-- *Main> greedySchedule requests
-- [Request (5,20),Request (20,25),Request (25,40),Request (45,60)]