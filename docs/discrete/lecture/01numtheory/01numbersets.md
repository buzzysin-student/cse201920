# Number Sets and their Properties <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./
[next]: ./02bases
[index]: ./index

## Natural Numbers

The set of natural numbers is the set of positive whole numbers, and zero:

$\mathbb{N}=\left\{0, 1, 2, ...\right\}$

In some definitions, $0$ is not included as an element, so it may be necessary to specify which definition of natural numbers that is being used.

## Integers

The set of integers is the set of both positive and negative whole numbers, and zero:

$\mathbb{Z}=\left\{...,-2, -1, 0, 1, 2, ...\right\}$

## Rational numbers

The set of rational numbers is the set of positive and negative numbers that can be represented by the result of dividing one integer by another.

$\mathbb{Q}=\left\{..., -\frac{2}{3},..., -\frac{1}{8}, ...,  0, ..., \frac{1}{4},..., \frac{3}{5}, ...\right\}$

## Irrational Numbers

The set of irrational numnbers contains all numbers that cannot be written as the quotient of two integers. A common example to prove this is using $\sqrt 2$.

$\overline{\mathbb{Q}}$

### Proof: $\sqrt2$ is irrational

> Theorem: $\sqrt 2$ is irrational - there are no integers $a$ and $b$ such that $\frac{a}{b} = \sqrt 2$

Proof:

Assume that $\sqrt{2} = \frac{a}{b}$ where $a,b\in\mathbb{Z}, \not \exist k: k|a,k|b$ ($a$ and $b$ are integers with no common factors).

$$
\begin{aligned}
\frac{a^2}{b^2}&=2
\\
a^2&=2b^2 &\implies 2|a
\\
\text{let }a=2n
\\
4n^2&=2b^2
\\
2n^2&=b^2 &\implies 2|b
\\
\text{let }b = 2m
\\
\end{aligned}
\\
\exists k: k|a,k|b \rarr k=2 \text{ (contradiction!)}
$$

However, this results in a contradiction as $a$ and $b$ have a common factor, $k = 2$.

Therefore $\sqrt 2$ is irrational.

## Real Numbers

The set of real numbers is the set of numbers that contains the union of $\mathbb{N, Z, Q}$. That means everything included above this paragraph.

## Complex Numbers

Complex numbers are an extension of real numbers that adds a secondary **imaginary** component to the real component. The imaginary unit is defined as follows:

$$ \bold{i}\text{ or }\bold{j} = \sqrt {-1} $$

Example complex numbers: $-\frac{2}{3}+2\bold j,-1+ \bold j\sqrt 3,\pi-e\bold j$.

Note that this new definiton also pertains to the real numbers, i.e. $2, \frac{3}{4},-\pi,\frac{\sqrt 2}{2}$ are real and also complex - the imaginary part is just equal to zero.

$$
\mathbb{C}=\left\{ a + b\bold j : a,b \in \mathbb{R} \right\}
$$
