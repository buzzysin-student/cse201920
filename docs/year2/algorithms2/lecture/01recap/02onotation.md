# O-Notation

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./01recap
[next]: ./03graphs
[index]: ../index

- [O-Notation](#o-notation)
  - [Recap](#recap)
    - [Table of Recaps and Analogues](#table-of-recaps-and-analogues)

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
