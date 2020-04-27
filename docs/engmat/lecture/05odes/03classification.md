# Classification of ODEs

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./02geometry
[next]: ./04hyperbolic
[index]: ./index

- [Classification of ODEs](#classification-of-odes)
  - [Classification by Order](#classification-by-order)
  - [Classification by Linearity](#classification-by-linearity)
  - [Classification by Homogeneity](#classification-by-homogeneity)

## Classification by Order

The order of the ODEs is the highest order derivative with respect to the independent variable (the denominator).

1. $\frac{dx}{dt} = 5xt$ is linear in x (has order 1)
2. $\frac{d^3x}{dt^3}=t+3sin(5t)$ has order 3 in x

## Classification by Linearity

An ODE is linear if the dependant variable (the numerator in the derivative) is not one of the following:

- Multiplied with its derivative
- Raised to a power
- Is a part of a non-linear function (sin, cos, exponential, ...)

1. $\frac{dy}{dx}+5y = 0$ is linear
2. $\frac{d^2y}{dx^2}-2\frac{dy}{dx}-y=0$ is linear
3. $\frac{dy}{dx}+\underline{\cos y} = 0$ is non-linear
4. $\frac{dy}{dx}+\underline{5y\frac{dy}{dt}} = 0$ is non-linear

**In general**, an ODE is linear if it can be written as follows:

$$
\begin{aligned}
&a_0(t)x + a_1(t)\frac{dx}{dt}+\cdots+a_n(t)\frac{d^nx}{dt^n} = f(t) \\
&\text{where }a_k(t) \text{ is a function of }t \\
\end{aligned}
$$

## Classification by Homogeneity

Given the above definition of a linear ODE, the right-hand-side of the equation (shown as $f(t)$) is zero:

$$
\begin{aligned}
&a_0(t)x + a_1(t)\frac{dx}{dt}+\cdots+a_n(t)\frac{d^nx}{dt^n} = 0
\end{aligned}
$$

|                | Linear                   | Non-linear             |
| -------------- | ------------------------ | ---------------------- |
| Homogenous     | $\frac{d^2y}{dx^2}-5y=0$ | \*Note                 |
| Non-homogenous | $\frac{dy}{dx}-x-y=0$    | $\frac{dy}{dx}+xy^2=0$ |

\*Note: by definition, homogenous ODEs are also linear.

