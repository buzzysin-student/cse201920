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
  - [Variables](#variables)
  - [Sentences](#sentences)
  - [Truth Tables](#truth-tables)
    - [Negation](#negation)
    - [Conjunction](#conjunction)
    - [Disjunction](#disjunction)
    - [Implication](#implication)
    - [Equivalence](#equivalence)
  - [Logical equivalences](#logical-equivalences)
    - [Shorthands](#shorthands)
    - [Identities](#identities)
  - [Tautologies and contradictions](#tautologies-and-contradictions)
    - [Law of the Excluded Middle](#law-of-the-excluded-middle)
    - [Law of non-contradiction](#law-of-non-contradiction)

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

In proof by contradiction, it is assumed that the property is false. The proof follows as normal, except that the final result is expected to be false, which implies that the property is actually true.

> See [this proof](../01numtheory/01numbersets.md#proof-irrational-numbers).

### Contrapositive proof

Contrapositive proofs are built much the same way as the prior, with the difference that you assume the opposite of both the antecedent and the consequant, since they are functionally equivalent.

$$
\text{P(n) = if n is even then n+1 is odd} \\
\text{P$'$(n) =if n is {\color{red}not} even then n+1 is {\color{red}not }odd } \\
\text{Example: let n = 3. 3 is not even. 3+1 = 4 is not odd} \\
\text{Conclude proof.}
$$

## Logic

### Statements

A declarative statement is a statement that can be evaluated to a true or false value.

Examples:

- I am 20 years old
- It is raining today
- This fruit :orange: is an apple

### Variables

A propositional variable is a symbol that represents a statement.

Example

- let $\phi$ = Today is Wednesday
- let $\psi$ = It is sunny

### Sentences

A sentence is a statement or combination of statements using the connectives of propositional logic - logical operators.

A sentence is valid if it follows the following form:

$$
\text{Let $\theta$ and $\phi$ be valid propositional statements.} \\
\text{Then, the following sentences are valid: } \\ \space \\
\begin{aligned}
               \theta  \\
  (       ¬\   \theta) \\
  (\theta \wedge\phi)  \\
  (\theta \vee  \phi)  \\
  (\theta \rarr \phi)  \\
  (\theta \lrarr\phi)
\end{aligned}
$$

### Truth Tables

My favourite part of propositional logic. Truth tables are a way to express the valuation (or truth-value) of a propositional statement.

#### Negation

Negation means true if statement is false.

| $\theta$ | $¬\ \theta$ |
| :------: | :---------: |
|    0     |      1      |
|    1     |      0      |

#### Conjunction

Conjunction means true if both statements are true.

| $\theta$ | $\phi$ | $\theta \wedge \phi$ |
| :------: | :----: | :------------------: |
|    0     |   0    |          0           |
|    0     |   1    |          0           |
|    1     |   0    |          0           |
|    1     |   1    |          1           |

#### Disjunction

Disjunction means at least one statement is true.

| $\theta$ | $\phi$ | $\theta \vee \phi$ |
| :------: | :----: | :----------------: |
|    0     |   0    |         0          |
|    0     |   1    |         1          |
|    1     |   0    |         1          |
|    1     |   1    |         1          |

#### Implication

Implication is difficult to explain. Imagine that $\phi$ is a resultant statement from assuming $\theta$.

It makes sense that:

- A false statement $\theta$ can result in a false conclusion $\phi$ - true
- A false statement $\theta$ can result in a correct conclusion $\phi$ - true
- A correct statement $\theta$ cannot result in a false conclusion $\phi$ - false
- A correct statement $\theta$ can result in a correct conclusion $\phi$ - false

| $\theta$ | $\phi$ | $\theta \rarr \phi$ |
| :------: | :----: | :-----------------: |
|    0     |   0    |          1          |
|    0     |   1    |          1          |
|    1     |   0    |          0          |
|    1     |   1    |          1          |

#### Equivalence

Equivalence means true when both statements have the same truth value.

| $\theta$ | $\phi$ | $\theta \lrarr \phi$ |
| :------: | :----: | :------------------: |
|    0     |   0    |          1           |
|    0     |   1    |          0           |
|    1     |   0    |          0           |
|    1     |   1    |          1           |

### Logical equivalences

Here are some important logical equivalences used for propositional logic:

#### Shorthands

- Implication simplified:
  - $\theta \rarr \phi \equiv ¬\theta \vee \phi$
- Equivalence as implication simplified:
  - $\theta \lrarr \phi \equiv (\theta \rarr \phi) \wedge (\phi \rarr \theta))$

#### Identities

- Idempotence
  - $\theta \wedge \theta \equiv \theta \vee \theta  \equiv \theta$
- Double Negation
  - $¬\ ¬\ \theta \equiv \theta$
- De Morgan's Laws
  - $¬ (\theta \vee \phi) \equiv ¬\theta \wedge ¬\phi$
  - $¬ (\theta \wedge \phi) \equiv ¬\theta \vee ¬\phi$
- Commutativity
  - $\theta \vee \phi \equiv \phi \vee \theta$
  - $\theta \wedge \phi \equiv \phi \wedge \theta$
- Associativity
  - $(\theta \vee \phi) \vee \psi \equiv \theta \vee (\phi \vee \psi)$
  - $(\theta \wedge \phi) \wedge \psi \equiv \theta \wedge (\phi \wedge \psi)$
- Distributivity
  - $(\theta \wedge \phi) \vee \psi \equiv (\theta \vee \psi) \wedge (\phi \vee \psi)$
  - $(\theta \vee \phi) \wedge \psi \equiv (\theta \wedge \psi) \vee (\phi \wedge \psi)$
- Contrapositive
  - $\theta \rarr \phi \equiv ¬ \theta \rarr ¬\phi$

### Tautologies and contradictions

A tautology is something that is true in all rows of the truth table.

#### Law of the Excluded Middle

I think of this as:

> _"Either something is happening, or it is not happening."_
>
> &mdash; Taharka Okai, 2020 &copy;

| $\theta$ | $¬\theta$ | $\theta \vee ¬\theta$ |
| :------: | :-------: | :-------------------: |
|    0     |     1     |           1           |
|    1     |     0     |           1           |

A contradiction is something that is false in all rows of the truth table.

#### Law of non-contradiction

I think of this as:

> _"Something cannot be both true and false at the same time."_
>
> &mdash; Taharka Okai, 2020 &copy;

| $\theta$ | $¬\theta$ | $\theta \wedge ¬\theta$ |
| :------: | :-------: | :---------------------: |
|    0     |     1     |            0            |
|    1     |     0     |            0            |
