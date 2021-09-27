# Data Characteristics <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./
[next]: ./
[index]: ./index

- [Distance measures](#distance-measures)
- [Numerical _space_ distance measures](#numerical-space-distance-measures)
- [Numerical _time_ distance measures](#numerical-time-distance-measures)
- [Symbolic distance measures](#symbolic-distance-measures)

## Distance measures

A distance measure D(a,b) between two components a,b must have the following properties:

| Property              | Symbolic Representation       | Description                                                                     |
| --------------------- | ----------------------------- | ------------------------------------------------------------------------------- |
| Nonnegative           | $D(a,b) \geq 0$               | Distance function gives positive or zero value                                  |
| Reflexive             | $D(a,b) = 0 \iff a = b$       | Distance function gives zero if inputs are identical                            |
| Symmetric             | $D(a,b) = D(b,a)$             | Distance function gives the same value for any order of the same two parameters |
| Triangular inequality | $D(a,b) \leq D(a,c) + D(c,b)$ | DIstance function satisfies the triangular inequality                           |

## Numerical _space_ distance measures

For any two points $(a,b)$ in $n$-dimensional Euclidean space, where $x=(x_1,x_2,...,x_n)$ and $y=(y_1,y_2,...,y_n)$, the **Minowski** distance of order **$p$** (or $p$-norm distance) is defined as:

$$
D_p(x,y) = {\left( \sum_{i} {\left| x_i - y_i \right|}^p \right)}^{\frac{1}{p}}
$$

- Manhattan distance (1-norm distance)
  - $D_1(x,y) = \sum_{i}{\left| x_i - y_i \right| }$
  - This is the sum of the absolute value of the differences. This can be thought as following gridlines in n-dimensional space
- Euclidean distance (2-norm distance)
  - $D_2(x,y) = \sqrt{\sum_{i}{\left| x_i - y_i \right| ^ 2}}$
  - This is equivalent to drawing a straight line between two points in a n-dimensional space, the "usual" method, "as the crow flies" (it may not help to think of this as a physical distance, but the analogy holds)
- Chess distance ($\infin$-norm distance)
  - $D_{\infin}(x,y) = \max{ \lbrace \left| x_i - y_i \right|  \text{ where } i \in \mathbb \lbrace 1,2,...,n \rbrace \rbrace }$

## Numerical _time_ distance measures

## Symbolic distance measures

- Syntatic text distance
  - A measure of how many certain transformations must be made to transform one string of text to another
    - e.g. Hamming distance (e.g. $\small \text{\textbf{Hamming}}(\text{wed},\text{bid}) = 2$ as "w" and "e" are substituted with "b" and "i" respectively
- Semantic text distance
