# Merge Sort <!-- omit in toc -->

- [Some Keywords](#some-keywords)
  - [In-place](#in-place)
  - [Stable](#stable)
- [Merge Sort Algorithm](#merge-sort-algorithm)
  - [The `MERGE` operation](#the-merge-operation)
    - [`MERGE` algorithm](#merge-algorithm)
    - [Analysis of the `MERGE` operation](#analysis-of-the-merge-operation)
  - [Analysis of Merge Sort](#analysis-of-merge-sort)
  - [Stability and in-placement](#stability-and-in-placement)
- [Working Python implementation](#working-python-implementation)

## Some Keywords

### In-place

A sort is **in-place** if no more than $O(1)$ size arrays are used in the algorithm.

### Stable

A sort is **stable** if two equal value elements are still adjacent to one another before and after the sort.

## Merge Sort Algorithm

### The `MERGE` operation

#### `MERGE` algorithm

```py
algorithm merge

Require an integer array `A` of length `n`

# Split the main array into two arrays
B <- A[[0, n/2]]
C <- A[[n/2+1, n-1]]
empty A

# This algorithm only works if the sub-arrays are sorted
assume B is sorted
assume C is sorted

i <- 0
j <- 0

for k <- 0 ... n - 1 do
  if B[i] < C[j] then
    A[k] <- B[i]
    i <- i + 1

  if C[j] <= B[i] then
    A[k] <- C[j]
    j <- j + 1

```

#### Analysis of the `MERGE` operation

### Analysis of Merge Sort

For each level $i$, there will be at most $2^{i-1}$ nodes there, because $i-1$ halves had taken place at that time. The length of the array in each node is given by $\lceil \frac{n}{2^{i+1}} \rceil$ (i.e. to distribute the size of the array equally amongst nodes).

Therefore the runtime of the merge operation in a given level $i$ is $O(\frac{n}{2^{i+1}})$

**Let the last level be denoted by $l$**

The length of arrays in the last level of the recursion tree is 1 (given by the termination condition). This means that $\lceil \frac{n}{2^{l}} \rceil = 1$

$$(1): \frac{n}{2^{l}} \leq 1 \implies n \leq 2^{l} \implies \log_2 n \leq l$$

The length of arrays in the layer $l-1$ will be 2 (since arrays are halved in size down layers, they must be doubled going up layers).

$$(2): \frac{n}{2^{l-1}} \gt 1 \implies n \gt 2^{l-1} \implies 1 + \log_2 n \gt l$$

Combining $(1)$ and $(2)$ give

$$ \log_2 n \leq l \lt 1 + \log_2 n$$

$$\therefore l = \lceil \log_2 n\rceil + 1$$

Total amount of work done, or the runtime, can be given by:

$$
\sum_{i=1}^{\text{levels}} \text{nodes} \times \text{merge runtime}
\newline
= \sum_{i=1}^{\lceil \log_2 n\rceil + 1} \cancel{2^{i-1}} \times O(\lceil \frac{n}{\cancel{2^{i+1}}} \rceil)
\newline
= \sum_{i=1}^{\lceil \log_2 n \rceil+1} O(n)
\newline
= O(n) + O(n \log_2 n)
\newline
= O(n \log_2 n)
$$

### Stability and in-placement

Merge Sort is stable as it preserves the order of equal elements in the `MERGE` operation.

Merge sort is not in-place as it uses $O(n/2)$ size intermediate sub-arrays, which is not in $O(1)$ or constant.

## Working Python implementation

Code can be found [here](./example.py)

```python
#!/usr/bin/env python

# ./example.py
from sys import argv
from math import inf


def main():
  args = list(map(int, argv[1:]))
  print(args)
  print(msort(args))


def merge(x):
  # `inf` acts as a buffer for the comparison
  # so that we don't query indices greater than
  # the size of the sub-array
  x1 = x[:len(x)//2] + [inf]
  x2 = x[len(x)//2:] + [inf]
  i = 0
  j = 0
  for k in range(len(x)): # Takes O(n) time
    if x1[i] < x2[j]:
      x[k] = x1[i]
      i += 1
    else:
      x[k] = x2[j]
      j += 1
  return x


def msort(x):
  if len(x) == 1: # O(1) time
    return x

  x[:len(x)//2] = msort(x[:len(x)//2])
  x[len(x)//2:] = msort(x[len(x)//2:])

  merge(x) # O(n) time

  return x


if __name__ == "__main__":
  main()
```
