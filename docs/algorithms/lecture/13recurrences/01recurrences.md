# Solving recurrences <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./index
[next]: ./index
[index]: ./index

- [What is a recurrence](#what-is-a-recurrence)
- [Solving a recurrence](#solving-a-recurrence)
  - [The substitution method](#the-substitution-method)
  - [Merge sort recurrence](#merge-sort-recurrence)

Disambiguation: let $T(n)$ be the runtime of an algorithm where the input is of size $n$.

## What is a recurrence

Recurrences arise as a consequence of an algorithm calling itself repeatedly to solve a problem. This occurs when a **divide and conquer** algorithm is used - create smaller sub-problems and solve for those sub-problems, then combine them.

## Solving a recurrence

### The substitution method

1. Replace all $O$ notation with constants and guess an upper bound
2. Guess a partial form of the solution
3. Use induction to prove guess in step 2

### Merge sort recurrence

1. a) Replace all O-notation with constants

$$
\begin{aligned}
T(1) &= O(1) \\
T(n) &= 2T(n/2) + O(n) \\
\text{becomes} &\rarr \\
T(1) &= c_1 \\
T(n) &= 2T(n/2) + c_2
\end{aligned}
$$

1. b) Guess an upper bound for the recurrence

$$
T(n) \leq Cn\log n
$$

2. Substitute our guess into the recurrence

$$
\begin{aligned}
  &\text{Assume that }T(n) \leq Cn \log n \\
  &\text{for every }n' < n
\end{aligned}
$$