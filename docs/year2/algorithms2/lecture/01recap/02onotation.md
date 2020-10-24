# O-Notation

[Previous Chapter][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./01induction
[next]: ./
[index]: ../index

- [O-Notation](#o-notation)
  - [Recap](#recap)
    - [Table of Recaps and Analogues](#table-of-recaps-and-analogues)
  - [Patterns with O- and other notations](#patterns-with-o--and-other-notations)
    - [Transitivity](#transitivity)
    - [Addition](#addition)
    - [Scalar multiplication](#scalar-multiplication)
    - [Multiplication of functions](#multiplication-of-functions)
    - [Squaring](#squaring)
    - [Exponentiation](#exponentiation)

## Recap

There are more strict vetsions of the O-Notations learnt in Algorithms 1 (let $f$ and $g$ be functions of $n$):

1. $o(g) = \left \{ f(n) : \forall C \exists n_0 : \forall n \geq n_0, f(n) \lt C \cdot g(n) \right \}$
2. $O(g) = \left \{ f(n) : \exists C, n_0, : \forall n \geq n_0, f(n) \leq C \cdot g(n) \right \}$
3. $\Theta(g) = \left \{ f(n) : \exists c,C, n_0, : \forall n \geq n_0, c \cdot g(n) \leq f(n) \leq C \cdot g(n) \right \}$
4. $\Omega(g) = \left \{ f(n) : \exists C, n_0, : \forall n \geq n_0, f(n) \geq C \cdot g(n) \right \}$
5. $\omega(g) = \left \{ f(n) : \forall C \exists n_0 : \forall n \geq n_0, f(n) \gt C \cdot g(n) \right \}$

### Table of Recaps and Analogues

| Big-O notation   | Loose notation | Limit Definition                                         | In words                          | Bounds          |
| ---------------- | :------------: | -------------------------------------------------------- | --------------------------------- | --------------- |
| $f\in o(g)$      |     $f<g$      | $\lim_{n\rarr\infty}{\frac{f(n)}{g(n)}} = 0$             | $f$ grows no faster than $g$      | strict upper    |
| $f\in O(g)$      |   $f \leq g$   | $\lim_{n\rarr\infty}{\frac{f(n)}{g(n)}} < \infty$        | $f$ grows at most as fast as $g$  | upper           |
| $f\in \Theta(g)$ |    $f = g$     | $\lim_{n\rarr\infty}{\frac{f(n)}{g(n)}} \in \reals_{>0}$ | $f$ grows about the same as $g$   | upper and lower |
| $f\in \Omega(g)$ |   $f \geq g$   | $\lim_{n\rarr\infty}{\frac{f(n)}{g(n)}} > 0$             | $f$ grows at least as fast as $g$ | lower           |
| $f\in \omega(g)$ |    $f > g$     | $\lim_{n\rarr\infty}{\frac{f(n)}{g(n)}} = \infty$        | $f$ grows no slower than $g$      | strict lower    |

## Patterns with O- and other notations

For the following notation below, let $f, g$ and $h$ be functions of $n$.

### Transitivity

If $f \in O(g)$ and $g \in O(h)$ then $f \in O(h)$

<details>

<summary>Proof</summary>

$f \in O(g) \implies \exists C_1, n_1 : f \leq C_1g$

$g \in O(h) \implies \exists C_2, n_2 : g \leq C_2h$

Then $\frac{1}{C_1}f \leq g$ and $\frac{1}{C_1C_2}f \leq h$ by substitution.

$\therefore \exists C_3, n_3 : f' \in O(h)$ where $f' = f, C_3 = C_1 \cdot C_2, n_3 = \max\left\{n_1, n_2\right\}$

</details>

### Addition

If $f \in O(h)$ and $g \in O(h)$ then $f + g \in O(h)$

<details>

<summary>Proof</summary>

$f \in O(h) \implies \exists C_1, n_1 : f \leq C_1h$

$g \in O(h) \implies \exists C_2, n_2 : g \leq C_2h$

$\therefore \exists C_3, n_3 : f' \in O(h)$ where $f' = f + g, C_3 = C_1 + C_2, n_3 = \max\left\{n_1, n_2\right\}$

</details>

### Scalar multiplication

If $f \in O(g)$ then $kf \in O(g), k \gt 0$ (No proof necessary)

### Multiplication of functions

If $f \in O(h)$ and $g \in O(h)$ then $f \cdot g$ is **not always** in $O(h)$

<details>

<summary>Proof</summary>

Counterexample: Let $f(n)=n, g(n)=n$

Both $f,g \in O(n)$

However, $f \cdot g = n^2 \notin O(n)$

</details>

### Squaring

If $f \in O(g)$ then $f^2 \in O(g^2)$

<details>

<summary>Proof</summary>

$f \in O(g) \implies \exists C, n_0 : f \leq Cg$

Squaring both sides of the inequality: $f^2 \leq C^2g^2$ is also true.

By inspection, this is the definition of $f^2 \in O(g^2)$

</details>

### Exponentiation

If $f \in O(g)$ then $2^f$ is not always in $O(2^g)$

<details>

<summary>Proof</summary>

Counterexample: let $f(n)=2n$ and $g(n)=n$

While it is true that $f \leq Cg$ where $C \geq 2$

It is not true that $2^n \in O(2^{2^n})$

</details>
