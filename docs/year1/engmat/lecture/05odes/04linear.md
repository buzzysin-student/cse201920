# Linear Homegenous ODEs <!-- omit in toc -->

- [Definition of linearity](#definition-of-linearity)
  - [Examples](#examples)
  - [Superposition theorem](#superposition-theorem)
- [Superposition and linearity](#superposition-and-linearity)

## Definition of linearity

### Examples

An example of linearity outside of ODEs is matrix multiplication as a linear operator.

1. $$\bold M \left( a\bold x \right) = a \bold{Mx}$$
2. $$\bold M(\bold x_1 + \bold x_2) = \bold{Mx_1} + \bold{Mx_2}$$
3. $$\bold M(a\bold x_1+b\bold x_2) = a\bold M\bold x_1 + b\bold M\bold x_2$$

See also: [Classification of ODEs by order](./03classification#classification-by-order).

### Superposition theorem

Given a linear homogenous ODE, the following is true:

$$
\begin{aligned}
  & \text{If }x \text{ is a solution of a linear homogenous ODE and }\\
  & x = x_1 + x_2, \text{then } Ax_1+Bx_2 \text{ is also a solution. }
\end{aligned}
$$

## Superposition and linearity

Every homogenous ODEs can be written under a linear operator, $\bold L$.

Consider the following ODE:

$$
\begin{aligned}
& t^2\frac{d^2x}{dt^2}-2t\frac{dx}{dt}+2x=\bold Lx=0 \\
& \\
& x(1) = 1, x'(1) = 0
\end{aligned}
$$

Then, the operator $\bold L$ can be written as:

$$
\bold L = t^2\frac{d^2}{dt^2}-2t\frac{d}{dt}+2
$$

Assume that we are given $x_1=t, x_2=t^2$ as solutions for this ODE. We can show this as follows:

$$
\begin{aligned}
&t^2\cdot0 - 2t\cdot 1 + 2\cdot t &=0 &\therefore x=t \text{ is a solution}\\
&t^2\cdot 2 - 2t \cdot 2t + 2\cdot t^2 &=0 &\therefore x=t^2 \text{ is a solution}
\end{aligned}
$$

Additionally 