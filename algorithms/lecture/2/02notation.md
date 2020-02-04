# O-notation <!-- omit in toc -->

- [Introductory concepts](#introductory-concepts)
  - [Algorithm runtime](#algorithm-runtime)
  - [Asymptotic complexity](#asymptotic-complexity)
- [Big O Notation (O-Notation)](#big-o-notation-o-notation)
  - [Racetrack principle](#racetrack-principle)

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

## Big O Notation (O-Notation)

:exclamation: **IMPORTANT**

O-notation is an extension of the above lemma:

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{If it holds that  \ensuremath{\exists C,n_0: f(n)\leq Cg(n)} and \ensuremath{n \geq n_0} then}>)

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{\ensuremath{f(n)\in O(g(n))}}>)

### Racetrack principle

Sometimes its not obvious whether a function asymptotically grows at least as fast as another.

When this is the case, the racetrack princple is needed:

![fn](<https://latex.codecogs.com/svg.latex?\inline \text{If \ensuremath{f(k)\geq g(k)} and \ensuremath{f'(n)\geq g'(n)} for every \ensuremath{n\geq k} then \ensuremath{f(n) \geq g(n)}}>)


