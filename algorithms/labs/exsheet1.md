# Worksheet 1 <!-- omit in toc -->

- [O-notation: Part 1](#o-notation-part-1)
  - [Answers](#answers)

## O-notation: Part 1

Give the formal proofs for:

1. ![fn](<https://latex.codecogs.com/svg.latex?\inline 10\in O(1)}>)
2. ![fn](<https://latex.codecogs.com/svg.latex?\inline 5n\in O(n)}>)
3. ![fn](<https://latex.codecogs.com/svg.latex?\inline n^2+10n\in O(\frac{1}{10}n^3)>)
4. ![fn](<https://latex.codecogs.com/svg.latex?\inline \sum_{i=1}^{n}i\in O(4n^2)>)

### Answers

1. ![fn](<https://latex.codecogs.com/svg.latex?\inline 10\in O(1)>)

   If 10 in O(1) then 0 <= 10 < c \* 1 for all n

   This is true when c = 10

   Since c exists, then 10 in O(1)

2. ![fn](<https://latex.codecogs.com/svg.latex?\inline 5n\in O(n)}>)

   If 5n in O(n) then 0 <= 5n <= c \* n

   This is true when c = 5, for all n

   Since c exists, then 5n in O(n)

3. ![fn](<https://latex.codecogs.com/svg.latex?\inline n^2+10n\in O(\frac{1}{10}n^3) >)

   ![fn](<https://latex.codecogs.com/svg.latex?\inline \text{If } f(n)=n^2+10n\in O(\frac{1}{10} n^3)\text{ then } 0\leq f(n)\leq \frac{c}{10} n^3>)
