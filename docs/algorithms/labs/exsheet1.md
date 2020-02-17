# Worksheet 1 <!-- omit in toc -->

- [O-notation: Part 1](#o-notation-part-1)
  - [Answers](#answers)

## O-notation: Part 1

Give the formal proofs for:

1. $10\in O(1)$
2. $5n\in O(n)$
3. $n^2+10n\in O(\frac{1}{10}n^3)$
4. $\sum_{i=1}^{n}i\in O(4n^2)$

### Answers

1. $10\in O(1)$

   $\text{If }10 \in O(1) \text{ then } 0 \leq 10 \leq c$

   $\therefore c = 10$

2. $5n\in O(n)$

   $\text{If }5n \in O(n)\text{ then }0 \leq 5n \leq cn$

   $\therefore c = 5$

3. $n^2+10n\in O(\frac{1}{10}n^3)$

   $\text{If } f(n)=n^2+10n\in O(\frac{1}{10} n^3)\text{ then } 0\leq f(n)\leq \frac{c}{10} n^3$
