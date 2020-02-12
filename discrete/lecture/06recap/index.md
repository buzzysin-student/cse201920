# Lecture 6

- [Lecture 6](#lecture-6)
  - [Recap](#recap)
    - [What is a group?](#what-is-a-group)
  - [Abelian Groups](#abelian-groups)

## Recap

### What is a group?

A groups is a set _G_ and a binary operator (**.**) which together satisfy the following conditions

1. Closure

   ![fn](<https://latex.codecogs.com/svg.latex?\forall x,y \in G, x\bullet y \in G>)

   In words: any operation on elements in the set should give only elements in the set.

2. Associativity

   ![fn](<https://latex.codecogs.com/svg.latex?\forall x,y \in G, (x\bullet y)\bullet z = x\bullet (y\bullet z)>)

   In words: The grouping of operations should not matter.

3. Identity

   ![fn](<https://latex.codecogs.com/svg.latex?\exists e\in G, \forall x \in G, e \bullet x = x \bullet e = x>)

   In words: There is an identity element for the operation.

4. Inverse

   ![fn](<https://latex.codecogs.com/svg.latex?\forall x \in G, \exists x^{-1}\in G : x \bullet x^{-1} = e>)

   In words: every element has an inverse.

## Abelian Groups

These types of group follow another axiom

- Commutativity

  ![fn](<https://latex.codecogs.com/svg.latex?\forall x,y \in G, x\bullet y = y\bullet x>)

  In words: order of operations don't matter.
