# Searches and Proofs <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./index
[next]: ./index
[index]: ./index

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

$O(1)$

This happens in the case that `t` is at the start of the array.

### Linear Worst-case runtime

$O(n)$

This is because the algorithm is forced to iterate through the entire array in either case where `t` is in the array or where `t` is not in the array.

### Average-case runtime

This is a bit more involved in terms of the calculations:

Let the set of inputs $S(n)$ be a sequence of consecutive integers such that the following holds:

$$
S(n) := \{ \text{array of length }n : A[i] \in \{0, 1, ..., k - 1\} \text{ for every } 0 \leq i \leq k - 1  \}
$$

In words: let the set of input arrays be arrays of length n that contain elements so that elements are within some maximum $k-1$.

The size of this set is the number of ways to list $n$ numbers given a choice from $0$ to $k-1$:

$\large A := \underset{n \text{ times}}{\underbrace{[A[i] \in \{0, 1, ..., k-1\}]}}$

There are $(k-1+1)^n = k^n$ possible ways to do this.

Therefore, the average case is calculated as:

$$
\frac{1}{|S(n)|} \underset{I\in S(n)}{\sum} T(I) = \frac{1}{k^n} \sum_{I\in S(n)}T(I)
$$

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

$O(1)$

THis is due to the same reason as the linear search - the first check could be the item that is being searched for (that just so happens to be in the middle of the array).

### Binary Worst-case runtime

Let $r$ be the number of recursive calls, and $n$ be the size of the array. Then it holds that:

$\frac{n}{2^r} \leq 2$

This is because of the boundary condition of the algorithm - the recursion stops then the array size is less than or equal to $2$.

$\therefore n\leq 2^{r+1}\implies \log_2 n\leq (r+1) \implies \log_2 n-1\leq r$

Since $\lceil \log_2{n} - 1\rceil \leq \log_2 n$, then the number of iterations is in $O(\log n)$