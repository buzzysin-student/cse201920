# Proofs <!-- omit in toc -->

[Previous Chapter][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[prev]: ./02logic
[next]: ./index
[index]: ./index

- [Definiton of a proof](#definiton-of-a-proof)
- [Definition of a property](#definition-of-a-property)
- [Types of proofs](#types-of-proofs)
  - [By Induction](#by-induction)
  - [By Contradiction](#by-contradiction)
  - [Contrapositive proof](#contrapositive-proof)
- [Logic](#logic)
  - [Statements](#statements)
  - [Truth Tables](#truth-tables)

## Definiton of a proof

A proof is a list of statements in sequence that are linked by [inference rules][prev].

$$
A_1, A_2, ..., A_n
$$

Above is a sequence of axioms, statements or assumptions, $A_k$, that lead to a result $A_n$.

## Definition of a property

A property is a description of a variable that can be evaluated to true or false.

Examples:

$$
\operatorname{Girl}(p) = \text{$p$ is a Girl} \\
\operatorname{Even}(n) = \text{$n$ is an even number} \\
\vdots
$$

## Types of proofs

### By Induction

Induction works by showing that the statement is true for a case, then showing that the statement is true for an increment on that inital case. If they are both true, then the result can be considered true by the inductive hypothesis, but with the initial case as a boundary condition.

Generic induction example:

$$
{\text{$P(a)$ holds $\wedge$ For all $n$, if $P(n)$ holds, then $P(n+1)$ holds} \above .5pt \text{For every $n \geq a, P(n)$}} \\
\\ \space \\
\text{where $P(n)$ is a property of n}
$$

Inductive proof example:

$$
\small
P(n) = \sum_{i=1}^{n} i = \frac{n(n+1)}{2}, \text{ for all $n \geq 1$}\\
\\ \space \\
\text{Assume P(1) holds}: \\
\\ \space \\
\text{Base case: } P(1) = \sum_{1}^{1} i = \frac{1(2)}{2} = 1 \\
\text{Inductive step: } \sum_{i=1}^{k+1} i = \sum_{i=1}^{k} i+(k+1) \\
= \frac{k(k+1)}{2} + (k+1) = (k+1) \left[ \frac{k}{2} + 1 \right] \\
= \frac{(k+1)(k+2)}{2}
$$

Therefore, by the inductive hypothesis, since the property holds for $k=1$ and for $n=k+1$, then for every $n \geq 1$ the property holds.

### By Contradiction

In proof by contradiction, it is assumed that the property

### Contrapositive proof

## Logic

### Statements

### Truth Tables
