# Searches and Proofs

## Linear Search

### Example

```py
algorithm linear_search

Require an integer array `A` with length `n`
Require an integer `t`

for i <- 0...n - 1 do # n times
  if A[i] == t then
    return i # O(1) time
return -1
```

Best-case runtime: ![fn](<https://latex.codecogs.com/svg.latex?\inline O(1) >)

This happens in the case that `t` is at the start of the array.

Worst-case runtime: ![fn](<https://latex.codecogs.com/svg.latex?\inline O(n) >)

This is because the algorithm is forced to iterate through the entire array in either case where `t` is in the array or where `t` is not in the array.
