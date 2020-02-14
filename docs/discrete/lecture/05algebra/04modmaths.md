# Groups and Modular Arithmetic <!-- omit in toc -->

- [Addition](#addition)
  - [Addition group example](#addition-group-example)
- [Multiplication](#multiplication)
  - [Multiplication group example](#multiplication-group-example)
- [Proving inverses in modular arithmetic](#proving-inverses-in-modular-arithmetic)

## Addition

### Addition group example

| +   | 0   | 1   | 2   | 3   | 4   | 5   |
| --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 1   | 2   | 3   | 4   | 5   |
| 1   | 1   | 2   | 3   | 4   | 5   | 0   |
| 2   | 2   | 3   | 4   | 5   | 0   | 1   |
| 3   | 3   | 4   | 5   | 0   | 1   | 2   |
| 4   | 4   | 5   | 0   | 1   | 2   | 3   |
| 5   | 5   | 0   | 1   | 2   | 3   | 4   |

![fn](<https://latex.codecogs.com/svg.latex?G=\langle [0,1,2,3,4,5], + \rangle>) is an abelian group under addition _mod 6_

- Closed? Yes
- Associative? Yes
- Identity? _e = 0_ Yes
- Inverse? Yes
  - inv(0) = 0
  - inv(1) = 5
  - inv(2) = 4
  - inv(3) = 3
  - ... _w.l.o.g_ (without loss of generality)
- Commutative? Yes

## Multiplication

### Multiplication group example

| ![fn][times] | 1   | 2   | 3   | 4   | 5   |
| ------------ | --- | --- | --- | --- | --- |
| 1            | 1   | 2   | 3   | 4   | 5   |
| 2            | 2   | 4   | 0   | 2   | 4   |
| 3            | 3   | 0   | 3   | 0   | 3   |
| 4            | 4   | 2   | 0   | 4   | 2   |
| 5            | 5   | 4   | 3   | 2   | 1   |

[times]: <https://latex.codecogs.com/svg.lates? \times>

![fn](<https://latex.codecogs.com/svg.latex?G=\langle [1,2,3,4,5], \times \rangle>) is **not** an abelian group under multiplication _mod 6_

- Closed? **No**, 0 is not in _G_
- Associative? Yes
- Identity? _e = 1_ Yes
- Inverse? **No**
- Commutative? Yes

**However** the group ![fn](<https://latex.codecogs.com/svg.latex?\inline G=\langle [1,5], \times \rangle>) is an abelian group under multiplication _mod 6_

## Proving inverses in modular arithmetic

**Theorem** - An element _n_ has an inverse _inv(n)_ under multiplication _mod p_ in which _n ![fn][times] inv(n) = 1_ if and only if _gcd(a,p) = 1_ for all _a_ in the group.

**Proof** -

> NOTE: remember that for "if and only if" proofs, both the precedent and the antecedent need to be proved.
