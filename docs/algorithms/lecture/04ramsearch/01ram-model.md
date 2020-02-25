# The RAM model <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./index.md
[next]: ./02searches.md
[index]: ./index.md

- [The RAM Model](#the-ram-model)
  - [Description](#description)
  - [Notation](#notation)
  - [Rules](#rules)

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

