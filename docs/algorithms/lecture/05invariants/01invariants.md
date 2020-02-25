# Loop invariants <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./index.md
[next]: ./02insertion.md
[index]: ./index.md

- [Definition](#definition)
- [Example with induction](#example-with-induction)

## Definition

A loop invariant is a property _P_ that does not change between iterations.

## Example with induction

Finding the maximum item in a list:

```py
algorithm maximum

Require an integer array `A` of length `n`

m = A[0]
for i = 1...n-1 do
  if A[i] > m then
    m = A[i]
return m
```

Loop invariant:

![fn](<https://latex.codecogs.com/svg.latex?m=\max [A[j]: 0\leq j \leq i ]>)

TODO: