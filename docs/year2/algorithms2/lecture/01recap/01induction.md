# Induction <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./
[next]: ./02onotation
[index]: ../index

- [Induction vs. Strong Induction](#induction-vs-strong-induction)
  - [Example of strong induction](#example-of-strong-induction)
- [Nested Induction](#nested-induction)

## Induction vs. Strong Induction

With regular induction, in the inductive hypothesis, it is assumed that the statement $S(k)$ is true.

In **strong induction**, it is assumed that from the base case (for example, from $S(0)$) to $S(k)$ is all true.

The steps to prove something by induction go as follows:

1. Base case - Prove $S(0)$
2. Inductive step - Assuming $S(0)...S(k)$ is true, prove $S(k+1)$

### Example of strong induction

Let $S(n)$ be the statement that $\sum_{i=0}^{n}x^i=\frac{x^{n+1}-1}{x-1},x\neq1$

Step 1 -

$$
\begin{aligned}
&S(0): &\sum_{i=0}^{0}x^i & =x^0 & =1 \\
& & \frac{x^1-1}{x-1} & & =1 \\
& \text{So } S(0) \text{ holds.}
\end{aligned}
$$

Step 2 -

$$
\begin{aligned}
&S(k+1): &\sum_{i=0}^{k+1}x^i&=\sum_{i=0}^{k}x^i + x^{k+1} \\
& & & =\frac{x^{k+1}-1}{x-1}+x^{k+1} \\
& & & =\frac{x^{k+1}(1-x+1)-1}{x-1} \\
& & & =\frac{x^{k+2}-1}{x-1}
\end{aligned}
$$

## Nested Induction

To solve a nested induction problem, the steps are as followed:

1. Base case - prove the base case considering one variable - i.e. let $S'(m)$ be the statement that $S(m,n)$ holds for $m = 0$
2. First inductive step - assuming that $S'(m)$ holds for all $m \geq 0$...
3. Nested base case - prove base statement with the other variable, i.e. key $S''(n)$ be the statement that $S(m, n)$ holds for $n = 0$ (which relies on $S'(m)$ being true)
4. Nested induction step - assuming that $S''(n)$ is true for all $n \geq 0$, show that $S(m,n)$ holds
