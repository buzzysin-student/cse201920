# Peak finding

`a_i` is a peak in an array if `a_(i-1)` and `a_(i+1)` are smaller than `a_i`

## Example:

```py
>>> arr = [1,9,2,8,3,7,4,6,5]
>>> peaks(arr)
[9,8,7,6]
...
```

# Well-defined

A problem is well-defined if it has a clearly defined end-state.

## Does every array has a peak?

  1. An array of length 0 has no peaks
  2. An array of length 1 has no peaks as it has no adjacent members
  3. An array of length 2 will return the index of the largest element

```bash

```