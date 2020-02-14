# Searches and Proofs <!-- omit in toc -->

[Previous][prev] | [Next][next] | [Index][index]

[prev]: ./01ram-model.md
[next]: ./index.md
[index]: ./index.md

- [Linear Search](#linear-search)
  - [Linear Example](#linear-example)
  - [Linear Best-case runtime](#linear-best-case-runtime)
  - [Linear Worst-case runtime](#linear-worst-case-runtime)
  - [Average-case runtime](#average-case-runtime)
- [Binary search](#binary-search)
  - [Binary Example](#binary-example)
  - [Binary Best-case runtime](#binary-best-case-runtime)
  - [Binary Worst-case runtime](#binary-worst-case-runtime)

## Linear Search

The array is searched from left to right until the element is found.

### Linear Example

```py
algorithm linear_search

Require an integer array `A` with length `n`
Require an integer `t`

for i <- 0...n - 1 do # n times
  if A[i] == t then
    return i # O(1) time
return -1
```

### Linear Best-case runtime

![fn](<https://latex.codecogs.com/svg.latex?\inline O(1) >)

This happens in the case that `t` is at the start of the array.

### Linear Worst-case runtime

![fn](<https://latex.codecogs.com/svg.latex?\inline O(n) >)

This is because the algorithm is forced to iterate through the entire array in either case where `t` is in the array or where `t` is not in the array.

### Average-case runtime

TODO: 

## Binary search

An ordered array is split in half until the item is found.

### Binary Example

```py
algorithm binary_search

Require a sorted integer array `A` of length `n`
Require an integer `t`

# BOUNDARY Condition
if |A| <= 2 then
  return the largest of A[0] and A[1]

if A[[n/2]] = t then
  return [[n/2]]

if A[[n/2]] > t then
  return binary_search(A[[0, n/2 - 1]], t)

else
  return binary_search(A[[n/2, n]], t)
```

### Binary Best-case runtime

![fn](<https://latex.codecogs.com/svg.latex?O(1)>)

THis is due to the same reason as the linear search - the first check could be the item that is being searched for (that just so happens to be in the middle of the array).

### Binary Worst-case runtime

Let _r_ be the number of recursive calls, and _n_ be the size of the array. Then it holds that:

![fn](<https://latex.codecogs.com/svg.latex?\frac{n}{2^r} \leq 2>)

This is because of the boundary condition of the algorithm - the recursion stops then the array size is less than or equal to _2_.

![fn](<https://latex.codecogs.com/svg.latex?\therefore n\leq 2^{r+1}\implies \log n\leq (r+1) \log 2>)

TODO: