# O-notation <!-- omit in toc -->

- [Introductory concepts](#introductory-concepts)
  - [Algorithm runtime](#algorithm-runtime)
  - [Asymptotic complexity](#asymptotic-complexity)
- [Big-O Notation (O-Notation)](#big-o-notation-o-notation)
  - [Example](#example)
  - [Racetrack principle](#racetrack-principle)
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

The best function of runtime depends on the size of the input (i.e. depending on the input length n)

    ! TODO -> Example here

### Asymptotic complexity

For large n, constants in the calculation of the complexity function of an algorithm matter less and may be ignored.

For small n, most algorithms are quite fast anyway.

> Lemma:
>
> ![fn](<https://latex.codecogs.com/svg.latex?\inline \text{Consider the increasing functions \ensuremath{f,g: \mathbb{N}\rightarrow\mathbb{N}} }>)
>
> ![fn](<https://latex.codecogs.com/svg.latex?\inline \text{\ensuremath{f(n)} asymptotically grows at least as fast as \ensuremath{g(n)}, if and only if:}>)
>
> ![fn](<https://latex.codecogs.com/svg.latex?\inline \text{\ensuremath{\exists n_0: f(n)\geq g(n)} and \ensuremath{n \geq n_0}}>)

## Big-O Notation (O-Notation)

:exclamation: **IMPORTANT**

O-notation is an extension of the above lemma:

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{If it holds that  \ensuremath{\exists C,n_0: f(n)\leq Cg(n)} and \ensuremath{n \geq n_0} then}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{\ensuremath{f(n)\in O(g(n))}}>)

### Example

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{Show that \ensuremath{0.5n \notin O(\frac{n}{\log_2n})}}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{Assume that \ensuremath{0.5n\in O(\frac{n}{\log_2n})}}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{This implies that there exists some \ensuremath{n\geq n_0} for which \ensuremath{0.5n \leq \frac{cn}{\log_2n}}}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \implies 0.5 \leq \frac{c}{\log_2n}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \implies \log_2n \leq 2c>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \implies n \leq 2^{2c}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{However, this is a contradiction because this does not hold for all } n\geq1>)

### Racetrack principle

Sometimes its not obvious whether a function asymptotically grows at least as fast as another.

When this is the case, the racetrack princple is needed:

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{If \ensuremath{f(k)\geq g(k)} and \ensuremath{f'(n)\geq g'(n)} for every \ensuremath{n\geq k} then \ensuremath{f(n) \geq g(n)}}>)

## Properties of Big-O

### Sum/product of Functions

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{If }f(n)\in O(n_1)\text{ and }g(n)\in O(n_2)\text{ then }f(n)+g(n)\in O(n_1+n_2)>)

Similarly:

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{If }f(n)\in O(n_1)\text{ and }g(n)\in O(n_2)\text{ then }f(n)\cdot g(n)\in O(n_1\cdot n_2)>)

### Polynomial Functions

#### False proof of polynomial in O(n)

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{Assume that }n^2\in O(n)>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \therefore n^2 = n+n+...+n\text{ (n times) = O(n) +O(n)+...+O(n) (n times)}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \therefore n^2 \in O(n)>) :x:

Orders can only be added a **known number of times**, i.e. O(n) cannot be added n times.
