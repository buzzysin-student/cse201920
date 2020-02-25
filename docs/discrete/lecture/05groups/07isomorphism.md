# Isomorphism <!-- omit in toc -->

- [Definition](#definition)
  - [Example of isomorphic groups](#example-of-isomorphic-groups)
  - [Example of real number isomorphism](#example-of-real-number-isomorphism)

## Definition

An isomorphism exists if there is a bijection between two sets that preserves operations. The bijection is the **_isomorphism_**, the groups are **_isomorphic_**.

$$
\text{Let }\lang G_1,\bullet \rang
\text{ and } \lang G_2,\star \rang \text{
  be groups }
$$

$$
f : G_1 \rightarrow G_2 \text{ is an isomorphism if }
$$

$$
\forall x,y \in G_1, f(x\bullet y)=f(x) \star f(y)
$$

### Example of isomorphic groups

| $\lang\{1,5\},\times\text{mod }6\rang$ |  1  |  5  |
| :------------------------------------: | :-: | :-: |
|                   1                    |  1  |  5  |
|                   5                    |  5  |  1  |

| $\lang\{1,-1\},\times\rang$ |  1  | -1  |
| :-------------------------: | :-: | :-: |
|              1              |  1  | -1  |
|             -1              | -1  |  1  |

| $\lang\{T,F\},\iff\rang$ |  T  |  F  |
| :----------------------: | :-: | :-: |
|            T             |  T  |  F  |
|            F             |  F  |  T  |

### Example of real number isomorphism

For $(\reals_{\gt 0},\times)$ to be isomorphic to $(\reals,+)$, there needs to be a function $f$ such that:

$$
\forall x,y \in R_{\gt 0}, f(x \times y) = f(x) + f(y)
$$

In words, if we choose two elements in the first set and multiply them, this must be the same as

Here, $f$ exists: $f(x)=\ln(x)$ because $\ln(xy)=\ln(x) + \ln(y)$
