# The _Fundamental Theorem of Arithmetic_ <!-- omit in toc -->

[Previous Chapter][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./05primes
[next]: ./
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

Assume that $P$ is the largest prime.

$$
\begin{aligned}
&\implies P+1 \notin \mathbb P \\
&\implies P + 1 = p_1p_2p_3..., \forall p_n \in \mathbb{P} &\tag{using FTA}
\\
\end{aligned}
$$
