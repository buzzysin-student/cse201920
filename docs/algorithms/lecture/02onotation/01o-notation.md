# O-notation <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./index.md
[next]: ./index.md
[index]: ./index.md

- [Introductory concepts](#introductory-concepts)
  - [Algorithm runtime](#algorithm-runtime)
  - [Asymptotic complexity](#asymptotic-complexity)
- [Big-O Notation (O-Notation)](#big-o-notation-o-notation)
  - [Example](#example)
  - [Racetrack principle](#racetrack-principle)
    - [Worked Example from Worksheet 1](#worked-example-from-worksheet-1)
- [Properties of Big-O](#properties-of-big-o)
  - [Sum/product of Functions](#sumproduct-of-functions)
  - [Polynomial Functions](#polynomial-functions)
    - [False proof of polynomial in O(n)](#false-proof-of-polynomial-in-on)

## Introductory concepts

### Algorithm runtime

Runtime is a function that maps input length of data into an algorithm to the number of operations that an algorithm will execute. There are different types of runtime considerations:

- Best-case runtime
- Worst-case runtime
- Average-case runtime

The best function of runtime depends on the size of the input (i.e. depending on the input length n).

### Asymptotic complexity

For large n, constants in the calculation of the complexity function of an algorithm matter less and may be ignored.

For small n, most algorithms are quite fast anyway.

> Lemma:
>
> $\text{Consider the increasing functions } f,g: \mathbb{N}\rightarrow\mathbb{N}$
>
> $f(n)\text{ asymptotically grows at least as fast as } g(n) \text{ if and only if:}$
>
> $\exists n_0: f(n)\geq g(n) \text{ and } n \geq n_0$

## Big-O Notation (O-Notation)

:exclamation: **IMPORTANT**

O-notation is an extension of the above lemma:

$\text{If it holds that }\exists C,n_0: f(n)\leq Cg(n)\text{ and }n \geq n_0\text{ then}$

$f(n)\in O(g(n))$

In a way, it can be thought that the function $f$ can be smaller than $g$ times some factor.

### Example

$\text{Show that } 0.5n \notin O(\frac{n}{\log_2n})$

$\text{Assume that }0.5n\in O(\frac{n}{\log_2n})$

$\text{This implies that there exists some }n\geq n_0 \text{ for which } 0.5n \leq \frac{cn}{\log_2n}$

$\implies 0.5 \leq \frac{c}{\log_2n}$

$\implies \log_2n \leq 2c$

$\implies n \leq 2^{2c}$

$\text{However, this is a contradiction because this does not hold for all } n\geq1$

### Racetrack principle

Sometimes its not obvious whether a function asymptotically grows at least as fast as another.

When this is the case, the racetrack principle is needed:

$\text{If }f(k)\geq g(k)\text{ and } f'(n)\geq g'(n)\text{ for every }n\geq k\text{ then }f(n) \geq g(n)$

#### Worked Example from Worksheet 1

$\text{Show that for }n\geq 1, n\leq e^n$

$\text{Step 1: Base case - For } n = 1, e^n \geq n \because e \geq 1$

$\text{Step 2: Derivative - Observe that }  \frac{d}{dn}(e^n) \geq \frac{d}{dn}(n)$

$\because e^n \geq 1 \implies n\geq \ln 1(0), \text{ so } n \geq 1 (\geq 0)$

$\text{Step 3: Invoke the racetrack principle - since } e^k \geq k \text{ for } k=1\newline\newline\text{ and } \frac{d}{dn}(e^n) \geq \frac{d}{dn}(n)\text{ for  }n \geq 1 \text{ then } e^n \geq n \text{ for all }n\geq k(=1)$

## Properties of Big-O

### Sum/product of Functions

$\text{If }f(n)\in O(n_1)\text{ and }g(n)\in O(n_2)\text{ then }f(n)+g(n)\in O(n_1+n_2)$

Similarly:

$\text{If }f(n)\in O(n_1)\text{ and }g(n)\in O(n_2)\text{ then }f(n)\cdot g(n)\in O(n_1\cdot n_2)$

### Polynomial Functions

#### False proof of polynomial in O(n)

$\text{Assume that }n^2\in O(n)$

$\therefore n^2 = n+n+...+n\text{ (n times) = O(n) +O(n)+...+O(n) (n times)}$

$\therefore n^2 \in O(n)$ :x:

Orders can only be added a **known number of times**, i.e. O(n) cannot be added n times.