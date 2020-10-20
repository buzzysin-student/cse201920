# The RAM model <!-- omit in toc -->

[Previous Chapter][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./01thetaomega
[next]: ./index
[index]: ./index

- [The RAM Model](#the-ram-model)
  - [Description](#description)
  - [Notation](#notation)
  - [Rules](#rules)
  - [Assumptions](#assumptions)
- [Runtime considerations](#runtime-considerations)
  - [Best case](#best-case)
  - [Worst case](#worst-case)
  - [Average case](#average-case)
  - [Goals of algorithm analysis](#goals-of-algorithm-analysis)
  - [Example analysis](#example-analysis)

## The RAM Model

### Description

The RAM model assumes that there exists some number of registers and an infinite memory array

| RAM (Memory)    |
| --------------- |
| ...             |
| ...             |
| ...             |
| ...             |
|                 |
| # **Registers** |
| 1               |
| 2               |
| 3               |
| 4               |

### Notation

- Access memory: M[0] and M[1], for example
- Mostly similar to Assembly Language

### Rules

In a single time step it is possible to:

- Load from memory into register
- Compute an operation (x, +, /, -)
- Move from register to memory

### Assumptions

- Input for algorithm is stored in read-only cells
- This space does not contribute to the memory used by the algorithm

## Runtime considerations

Runtime can be computed for different situations:

- Specific input, i.e. what is the exact number of operations given a certain input?
- Best case, i.e. least number of operations?
- Worst case, i.e. most number of operations?
- Average case, i.e. average number of operations given a set of inputs?

Here are some standard definitions:

Let $S(n)$ be the set of possible inputs of length $n$ for an algorithm.

For $I \in S(n)$, let $T(I)$ be the runtime for this specific input.

### Best case

$$\large \underset{I\in S(n)}{\min} T(I)$$

In words: the runtime for an input $I$ where I is in the set of possible input of length $n$, such that $T(I)$ is a **minimum**.

### Worst case

$$\large \underset{I\in S(n)}{\max} T(I)$$

In words: the runtime for an input $I$ where I is in the set of possible input of length $n$, such that $T(I)$ is a **maximum**.

### Average case

$$\large \frac{1}{|S(n)|} \underset{I\in S(n)}{\sum} T(I)$$

In words: the average of the runtime of all possible inputs of length $n$ ($|S(n)|$ denotes the size of the set of inputs).

### Goals of algorithm analysis

- Runtime analysis: to compute the number of operations that take O(1) time
- **Space analysis**: to compute the amount of memory used

### Example analysis

```py
algorithm

Require an integer array `A` with length `n`

s <- 0 # takes O(1) time
for i <- 0...n - 1 do # n times
  for j <- i...2i do # i+1 times
    s <- A[i] + s # takes O(1) time
```

This algorithm executes $i+1$ in the inner loop and $n$ times in the outer loop. So the total number of loops can be summed as follows:

$$O(1)+\sum_{i=0}^{n-1} (i+1)\times O(1)$$
$$O(1)+O(1)\sum_{i=0}^{n-1} (i+1)$$
$$O(1)+O(1)\times [\sum_{i=0}^{n-1} i + \sum_{i=0}^{n-1} 1]$$
$$O(1)+O(1)\times [\frac{n(n-1)}{2} + n]$$
$$O(1)+O(1)\times \frac{n(n+1)}{2}$$
$$O(1)+O(\frac{n^2+ n}{2})$$
$$O(1)+O(n^2) = O(n^2)$$

In general, if there is a nested loop:

$$
\text{other runtime outside loop}\space+
$$

$$
\sum_{\text{inner loop variable}}^{\text{outer loop count}} (\text{inner loop count in terms of inner loop variable})
$$
