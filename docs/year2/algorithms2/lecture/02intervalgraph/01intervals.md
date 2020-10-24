# Greedy Algorithms and Interval Scheduling <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./
[next]: ./02correctness
[index]: ./index

- [Requests](#requests)
- [Greediness](#greediness)
  - [Heuristic](#heuristic)
  - [The algorithm](#the-algorithm)

## Requests

Consider the structure of a request - $(s, f)$ where $0 \leq s \leq f$ - and the problem of taking a set of requests $\mathcal{R}$ and finding the **largest compatible set**, where...

<center>

> ...compatible means one request does not overlap with another, i.e. $(s,f)$ and $(s',f')$ are compatible if and only if either $s \geq f'$ or $s' \geq f$

</center>

This is called the interval scheduling problem.

## Greediness

A greedy algorithm is one such that a non-optimal solution is used as a basis, and subsequent steps are then used to produce an optimal solution. One such way to solve the interval scheduling problem is to start with a non-optimal set of requests $A = \{\}$ (empty is non-optimal if $\mathcal{R}$ is non-empty)

### Heuristic

The algorithm needs a way to guage the priority of requests against others in order to schedule them. This is the **heuristic** of the algorithm.

One such heuristic could be the request that finishes the earliest and is still compatible

### The algorithm

Here is a Haskell implementation because I'm bored.

```hs
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
```

Code file is [here](./01intervals.hs). Seriously, Haskell is amazing for conceptualising stuff like this :heart:.
