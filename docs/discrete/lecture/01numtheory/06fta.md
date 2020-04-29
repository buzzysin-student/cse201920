# The _Fundamental Theorem of Arithmetic_ <!-- omit in toc -->

[Previous Chapter][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./05primes
[next]: ./index
[index]: ./index

- [The Fundamental Theorem of Arithmetic](#the-fundamental-theorem-of-arithmetic)
  - [Examples](#examples)
- [Proof of no largest prime](#proof-of-no-largest-prime)

## The Fundamental Theorem of Arithmetic

The Fundametal Theorem of Arithmetic is quite a scary name, but all it really means is that every number _greater than one_ (since 1 is not prime) can be expressed as a product of primes.

### Examples

$$
% Definitions
\def\x#1{\times #1}
% End Definitions
\begin{aligned}
40 &= 2^3\x5 \\
94 &= 2\x47 \\
53 &= 53 ~(\text{53 is prime})
\end{aligned}
$$

## Proof of no largest prime

Assume that there is a largest prime = $p_n$.

$$
% Definitions
\def\aligned#1{\begin{aligned}#1\end{aligned}}
% End Definitions

\aligned{
  &\text{Consider } P = p_1p_2p_3...p_n+1 \\
  &\implies \frac{P}{p_k} \text{ has remainder }1, \forall k\in\{1,2,...,n\} \\
  &\implies P \text{ only has divisors } 1, P \\
  &\implies P \in \mathbb P \\
  &\text{Consider that } P \gt p_n \text{ and } p \text { is prime}
}
$$

However, this contradicts the statement the $p_n$ is the largest prime, so the assumption that P is the largest prime is false. Therefore there is no largest prime.