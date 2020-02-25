# Introduction to Algorithms <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./index.md
[next]: ./index.md
[index]: ./index.md

- [Example: Peak-finding](#example-peak-finding)
  - [Pseudocode](#pseudocode)
  - [Algorithm completion state](#algorithm-completion-state)
  - [Proof that every array has a peak](#proof-that-every-array-has-a-peak)
- [An improvement](#an-improvement)

## Example: Peak-finding

`a_i` is a peak in an array if `a_(i-1)` and `a_(i+1)` are smaller than `a_i`. What this means is that an element is a peak if its neighbours are not larger than the element.

```py
>>> arr = [1,9,2,8,3,7,4,6,5]
>>> peaks(arr)
[9,8,7,6]
...
```

### Pseudocode

```c
/**
 * Peak-finding in c
 */

// Returns the position of a peak in an array
int peak(int *A, int len) {
  // If the first element is a peak
  if (A[0] >= A[1])
    return 0;

  // If the last element is a peak
  if (A[len - 1] >= A[len - 2])
    return len - 1;


  for int (i = 1; i < len - 1; i++){
    // If an element is greater than or equal to
    // both its neighbours
    if (A[i] >= A[i - 1] && A[i] >= A[i + 1])
      return i;
  }

  return -1;
}
```

```py
# Peak finding in pseudocode

Require an integer array `A` of length `n`

if A[0] >= A; then
  return 0

if A[n-1] >= A[n-2]; then
  return n-1

for i = 1...n-2 do
  if A[i] >= A[i-1] and A[i] >= A[i+1] then
    return i;

return -1;
```

### Algorithm completion state

> Aside: Well-defined algorithm
>
> A problem is well-defined if it has a clearly defined end-state.

1. An array of length 0 has no peaks
2. An array of length 1 has no peaks as it has no adjacent members
3. An array of length 2 will return the index of the largest element

### Proof that every array has a peak

$\text{Suppose that } A \text{ is an array of length } n, \{ a_0, a_1, a_2, ..., a_{n-1} \}, \text{ and has no peaks. }$

$\text{Then }a_1\geq a_0 \text{as otherwise } a_1 \text{ would be a peak.}$

$\text{Then }a_2\geq a_1 \text{ as otherwise }a_2 \text{ would be a peak.}$

$\text{This reasoning cascades for all }i\leq n - 1, \text{ i.e. }a_i \geq a_{i-1}.$

$\text{However, this implies that } a_{n-1} \text{ is a peak, which is a contradiction.}$

## An improvement

```py
# A recursive implementation

algorithm fast_peak_finding

Require an integer array `A` with length `n`

# NOTE: A[[a]] means index of A at floor(a)
# NOTE: A[a,b] means slice of array from a to b

# If the array is one element long
if n == 1 then
  return 0

# If the array is two elements long
if n == 2 then
  return indexOf(max(A[0], A[1]))

# If the center element is a peak
if A[[n/2]] is a peak then
  return [[n/2]]

# If previous element is larger than middle
# Then find peak in lower half
if A[[n/2 - 1]] >= A[[n/2]] then
  return fast_peak_finding A[[0, n/2 - 1]]

# Otherwise find peak in upper half
else
  return n/2 + 1 + fast_peak_finding A[[n/2 + 1, n - 1]]
```
