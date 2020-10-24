# Correctness Proofs for Interval Scheduling <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./01intervals
[next]: ./03bridges
[index]: ./index

- [Overview](#overview)
- [Proofs](#proofs)

## Overview

Here is the psuedocode for the algorithm discussed [before][prev].

```haskell
algorithm GreedySchedule

input set R of `n` requests (integer pairs (s, f) where 0<=s<=f)

start
  sort R such that the finishing times f_i are ordered
  let A = []
  let lastF = 0
  for 1..i do
    if s_i greater than lastF then
      A = A + (s_i,f_i)
      lastf = f_i
  output A
end
```

To formalise this mathematically:

- Let $A_n=\{\}$ be the solution at $n$ iterations
- Let $A^+_n$ be the index of the interval $(s,f)$ in $\mathcal{R}$ such that $A_{n-1}\cup\{(s, f)\}$ is still compatible
- Let $A_0=\empty$ and $A_{i+1}=A_i\cup\{A^+_i\}$
- Let $t=\max\{i: A_i \text{ is defined} \}$

## Proofs

Prove the following statements:

- Lemma: The algorithm always outputs $A_t$
- Lemma: $A_t$ is a compatible set
- Lemma: $A_t$ is a maximum compatible subset of $\mathcal{R}$
- Theorem: The algorithm outputs $A_t$ which is a **Maxiumum Compatible Set** (i.e. the best solution)

This overall results in a proof of the correctness of this algorithm.