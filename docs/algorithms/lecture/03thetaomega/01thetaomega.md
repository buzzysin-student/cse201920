# Theta and Omega <!-- omit in toc -->

[Previous][prev] | [Next][next] | [Index][index]

[prev]: ./index.md
[next]: ./index.md
[index]: ./index.md

- [Limitations of Big-O](#limitations-of-big-o)
- [Theta](#theta)
  - [Properties of Theta](#properties-of-theta)
    - [Mutual Asymptotic Growth](#mutual-asymptotic-growth)
      - [Proof 1](#proof-1)
    - [Mutual Asymptotic Bounds](#mutual-asymptotic-bounds)
      - [Proof 2](#proof-2)
- [Omega](#omega)
  - [Properties of Omega](#properties-of-omega)
    - [Inverse Big-O](#inverse-big-o)
      - [Proof 3](#proof-3)

## Limitations of Big-O

With Big-O, it is possible to define the slowest possible runtime for an algorithm, but this could also mean that the algorithm could run faster than what _O(f(n))_ specifies.

For example:

$\text{An algorithm runs with }O(g(n))$

$\newline \therefore \text{ there is some function and constant } f,c  \text{ such that }\newline\newline 0\leq f(n) \leq cg(n) \text{ for all n above a certain value.}$

What this means is that there is a set of functions denoted by _f_ that is less than _g(n)_. This means that an algorithm that runs in _O(n^2)_ could also run in _O(sqrt(n))_ or _O(log n)_. It is not entirely clear.

## Theta

The definition of _Theta(n)_ is as follows:

$\newline \text{If }f(n) \in \Theta(g(n))\text{ then} \newline \newline \exists c_1, c_2 \> 0: 0 \leq c_1 g(n) \leq f(n) \leq c_2 g(n)\newline\newline\text{for all n greater than a certain value }$

In words, there is a function _g_ that asymptotically bounds (or "sandwiches") the function _f_ up to positive constants.

### Properties of Theta

#### Mutual Asymptotic Growth

The first property of _Theta(f(n))_ is as follows:

$f\in\Theta(g) \Leftrightarrow f\in O(g) \wedge g \in O(f)$

In words: If there is a function _g_ that asymptotically bounds _f_, then _g_ grows asymptotically at least as fast as _f_ up to a constant, and also _f_ grows asymptotically at least as fast as _g_ up to a constant (and vice versa).

##### Proof 1

$\text{If }f\in\Theta(g)$

$\text{Then }0\leq c_1 g \leq f \leq c_2 g\text{ (given that }c_1, c_2 \> 0)$

$\therefore g\in O(f) \because f\leq c_2 g$

$\text{Also }\therefore f\in O(g) \because g\leq \frac{1}{c_1}f$

In words:

> If _f_ is sandwiched by _g_
>
> There is some positive integer constant _c_2_ such that _c_2 g_ is always greater than _f_ after a point.
>
> Additionally, there is some positive integer constant _c_1_ such that _1/(c_1) f_ is always greater than _g_ after a point.
>
> Therefore the functions grow asymptotically at least as fast as each other.

#### Mutual Asymptotic Bounds

The second property of _Theta(f(n))_ is as follows:

$f\in\Theta(g) \Leftrightarrow g\in\Theta(f)$

In words: if _f_ asymptotically bounds _g_ up to constants, then _g_ asymptotically bounds _f_ up to constants (and vice versa).

##### Proof 2

$\text{If }f\in\Theta(g)$

$\text{Then }0\leq c_1 g \leq f \leq c_2 g\text{ (given that }c_1, c_2 \> 0)$

$\text{Note that }g \leq \frac{1}{c_1}f$

$\text{Also note that }g \geq \frac{1}{c_2}f$

$\therefore 0 \leq \frac{1}{c_2}f \leq g \leq \frac{1}{c_1}f$

$\text{Which is the definition for }g \in \Theta(f).$

This proof is a little easier to contextualise in words by reading the equations, so there is no text explanation here.

## Omega

The definition of _Omega(n)_ is as follows:

$\text{If }f\in\Omega(g)$

$\newline \text{Then }\exists c \> 1:0\leq g \leq cf \newline \newline \text{for all n greater than a certain value }$

### Properties of Omega

#### Inverse Big-O

Omega is special in that it has the "opposite" definition to Big-O. This gives it the following property:

$f\in\Omega(g)\Leftrightarrow g \in O(f)$

##### Proof 3

$\text{If }f\in\Omega(g) \text{ then }\exists c_1: 0 \leq g \leq c_1f(n)$

$\text{Compare with }g\in O(f) \rightarrow \exists c_2: 0 \leq g \leq c_2f(n)$

$\text{Note that if }ac_1 = bc_2, \text{ where } a,b > 0\text{, the statement holds. }$
