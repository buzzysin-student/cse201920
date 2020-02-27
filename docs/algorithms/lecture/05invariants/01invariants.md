# Loop invariants <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./index.md
[next]: ./02insertion.md
[index]: ./index.md

- [Definition](#definition)
- [Example with induction](#example-with-induction)
  - [Initialisation](#initialisation)
  - [Maintenance](#maintenance)
  - [Termination](#termination)

## Definition

A loop invariant is a property $P$ that does not change between iterations.

Note - there is the rather annoying property of proving loop invariants that there is rarely a way to prove a statement using only mathematical notation, and if there is, it can be easy to get confused by all of the notation.

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

$m=\max \{A[j]: 0\leq j \lt i \}$

### Initialisation

This asks the question - does the loop invariant hold before the first iteration?

Before iteration $i = 1$:

Let $m_i$ be the value of $m$ before iteration $i$.

$m_1 = A[0]$ and $\max\{ A[j] : 0 \leq j \leq 1\} = A[0]$, so the invariant holds.

### Maintenance

This asks the question - does the loop invariant hold before the next iteration?

$$
m_{i+1}  = \max \{ m_i, A[i]\} (1)
\newline = \max \{ \max \{ A[j] \leq j \lt i\}, A[i]\}(2)
\newline = \max \{ A[j] : 0 \leq j \lt i + 1 \} (3)
$$

In words, the next iteration's value of $m$ is the maximum between the previous iteration's value of m and the current value of $A[i]$ (1). This is the same as taking the maximum of the list from $0$ to $i-1$ and comparing that maximum to $A[i]$ (2). Since this is also the same as finding the maximum up to and including $A[i]$, the loop invariant holds (3).

### Termination

This asks the question - does the loop invariant hold at the end of the loop?

After iteration $i=n-1$

$$
m_{n-1}  = \max\{ m_{n-2}, A[n-1]\}
\newline = \max \{ \max \{ A[j] : 0 \leq j \lt n-2 \}, A[n-1] \}
\newline = \max \{ A[j] : 0 \leq j \lt n - 1\}
$$

Therefore at the end of the loop, $m$ contains the maximum value of $A$ such that $m \geq A[j], \forall j \in [0,n-1]$
