# Insertion sort <!-- omit in toc -->

[Previous Chapter][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./01invariants.md
[next]: ./index.md
[index]: ./index.md

## Insertion sort

```python
algorithm insertion_sort

Require an integer array `A` of size `n`

# For every item in the array
for j = 1...n-1 do
  # Set v as the number to move
  v <- A[j]
  # Set i as the number before j
  i <- j-1
  # While i is not the index for the start
  # of the array, and while the current
  # comparison number not ordered
  while i >= 0 and A[i] > v do
    # Set the next number to be
    # the value of the previous
    A[i+1] <- A[i]
    # Decrement i
    i <- i - 1


  # This has the effect of moving
  # `v` down the list to its sorted
  # position.

  # At the end of the loop, set v to its final
  # position
  A[i+1] <- v
```

### Loop invariant

> Note: this proof is _very_ informal

Invariant: $A[0,j-1]$

Initialisation: at iteration $j=1$, A[0] is sorted.

Maintenance: at iteration $j \geq 1$:

$A[j]$ is inserted into it's correct position within $A[0,j]$. **Another internal loop invariant is required to prove this formally**.

Termination: at iteration $j=n-1$, the invariant states that $A[0,n-1]$ is sorted, which is the entire array $(\because A \equiv A[0,n-1])$.

### Worst-case runtime

- The outer loop runs from $j=1$ to $n-1$ ($n-1$ times)
- The inner loop runs from $i=j-1$ to $i=0$ ($j$ times) in the worst-case
- All other operations take $O(1)$ constant time.

$$
\text{Runtime } = \sum_{j=1}^{n-1} j\cdot O(1)
\newline = O(1) \sum_{j=1}^{n-1} j=O(1)\frac{n(n-1)}{2}=O(\frac{1}{2}(n^2+n))
\newline = O(n^2)
$$

### Average-case runtime

On average, one would expect that about half of the numbers before index $A[j]$ are both bigger and smaller than $A[j]$. This would require moving $A[j]$ to approximately $A[j/2]$. This means the inner loop would run approximately $j/2$ times.

$$
\text{Runtime } = \sum_{j=1}^{n-1} \frac{j}{2}\cdot O(1) = O(n^2)
$$