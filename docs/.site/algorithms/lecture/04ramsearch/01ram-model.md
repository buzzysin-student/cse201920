# The RAM model <!-- omit in toc -->

[Previous][prev] | [Next][next] | [Index][index]

[prev]: ./index.md
[next]: ./02searches.md
[index]: ./index.md

- [The RAM Models](#the-ram-models)
  - [Description](#description)
  - [Notation](#notation)
  - [Rules](#rules)
- [Runtime considerations](#runtime-considerations)
  - [Goals of algorithm analysis](#goals-of-algorithm-analysis)
  - [Example](#example)

## The RAM Models

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

## Runtime considerations

Runtime can be computed for different situations:

- Specific input, i.e. what is the exact number of operations given a certain input?
- Best case, i.e. least number of operations?
- Worst case, i.e. most number of operations?
- Average case, i.e. average number of operations given a set of inputs?

### Goals of algorithm analysis

- Runtime analysis: to compute the number of operations that take O(1) time
- **Space analysis**: to compute the amount of memory used

### Example

```py
algorithm

Require an integer array `A` with length `n`

s <- 0 # takes O(1) time
for i <- 0...n - 1 do # n times
  for j <- i...2i do # i+1 times
    s <- A[i] + s # takes O(n) time
```
