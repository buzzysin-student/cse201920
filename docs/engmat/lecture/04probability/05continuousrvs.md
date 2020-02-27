# Continuous RVs <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./02geometry.md
[next]: ./04hyperbolic.md
[index]: ./index.md

- [Uniform random variables](#uniform-random-variables)
- [The cumulative distribution function](#the-cumulative-distribution-function)

## Uniform random variables

This is a probability distribution where the following holds:

For an interval $[0, 1]$ the probability of $X$ falling within this range is defined as:

$P(a < X\leq b)=\frac{1}{b-a}\int_a^bf(x)dx$

or sometimes

$P(a < X\leq b)=\frac{1}{b-a}\int_{-\infty}^{\infty}f(x)dx$

This is known as the **probability density function (p.d.f)**.

## The cumulative distribution function

