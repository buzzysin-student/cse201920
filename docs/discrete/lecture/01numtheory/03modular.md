# Modular Arithmetic <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./02bases
[next]: ./04gcd-lcm
[index]: ./index

Modular arithmetic is defined in such a way that when the result of a computation exceeds the value that is being modulated by, the result cycles back to 0 and begins counting up again. Here are some examples of computations under modular arithmetic.

## Addition

| $+ \mod 5$ |  0  |  1  |  2  |  3  |  4  |
| :--------: | :-: | :-: | :-: | :-: | :-: |
|     0      |  0  |  1  |  2  |  3  |  4  |
|     1      |  1  |  2  |  3  |  4  |  0  |
|     2      |  2  |  3  |  4  |  0  |  1  |
|     3      |  3  |  4  |  0  |  1  |  2  |
|     4      |  4  |  0  |  1  |  2  |  3  |

## Products

| $\times \mod 5$ |  0  |  1  |  2  |  3  |  4  |
| :-------------: | :-: | :-: | :-: | :-: | :-: |
|        0        |  0  |  0  |  0  |  0  |  0  |
|        1        |  0  |  1  |  2  |  3  |  4  |
|        2        |  0  |  2  |  4  |  1  |  3  |
|        3        |  0  |  3  |  1  |  4  |  2  |
|        4        |  0  |  4  |  3  |  2  |  1  |

## Properties of modular numbers

Given a number $x \mod n$, the following property holds:

$$
n \mod m = a + bm \\
\text{ where } a \in \left\{0,1, ..., m-1\right\}, b \in \mathbb{Z}
$$

This means the following statements are equivalent:

$$
\begin{aligned}
  & & 25 &\mod 3 \\
= & & 3(8) + 1 &\mod 3 \\
= & & 3(k) + 1 &\mod 3, \forall k\in \mathbb{Z} \\
= & & 3(0) + 1 &\mod 3 \\
= & & 1 &\mod 3
\end{aligned}
\\ \above .4pt \\
\therefore 25 \mod 3 \equiv 1 \mod 3
$$

## Solving equations

### Linear equations

Example:

$$
\begin{aligned}
  &(1)& 3+x &= 1 \mod 5 \\
  &(2)& 2y  &= 3 \mod 5
\end{aligned}
$$

Equation (1):

$$
\begin{aligned}
&(1)& 3 + x &= 1 \mod 5 \\
&&    3 + x &= 6 \mod 5 \\
&&        x &= 3 \mod 5
\end{aligned}
$$

Equation (2):

$$
\begin{aligned}
&(2)& 2y &= 3 \mod 5 \\
&&    2y &= 8 \mod 5 \\
&&     y &= 4 \mod 5
\end{aligned}
$$

### Simultaneous equations

$$
\begin{aligned}
 x + 2y &= 4 \mod 5 \\
3x + 4y &= 2 \mod 7 \\
\end{aligned}
\\
\text{Let }x = 0:
\\
2y = 4 \mod 5 \\
 y = 2 \mod 5 \\
\space \\
4y = 2 \mod 7 \\
4y = 16 \mod 7 \\
 y = 4 \mod 7 \\
\space \\
y = 5k_1 + 2 \\
5 k_1 + 2 = 4 \mod 7 \\
5k_1 = 2 \mod 7 \\
5k_1 = 30 \mod 7 \\
k_1 = 6 \mod 7 \\
y = 32 \\
$$

> Note - this is just one out of 35 solutions (from $x = 0 \rarr x = 34$)
