# GCD and LCM <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./03modular
[next]: ./05primes
[index]: ./index

- [Greatest common divisor definition](#greatest-common-divisor-definition)
  - [Common divisor](#common-divisor)
  - [Greatest common divisor](#greatest-common-divisor)
  - [Euclid's Algorithm](#euclids-algorithm)
    - [In words](#in-words)
    - [Haskell implentation](#haskell-implentation)
- [Lowest common multiple definition](#lowest-common-multiple-definition)
  - [Common multiple](#common-multiple)
  - [Lowest common multiple](#lowest-common-multiple)
- [Finding GCD and LCM using primes](#finding-gcd-and-lcm-using-primes)
  - [GCD with primes](#gcd-with-primes)
  - [LCM with primes](#lcm-with-primes)

## Greatest common divisor definition

### Common divisor

A common divisor is any number that divides into any two (or more) numbers.

$$
\text {Let common factors := $\mathbb F_c(a,b) $ = \{ $f$: $f|a$ and $f|b$ \}}
$$

### Greatest common divisor

Consider the numbers $a$ and $b$. If there is a number such that $c$ divides a and b, and $c$ is divisible by all factors of $a$ and $b$, then $c$ is the Greatest Commmon Factor of $a$ and $b$.

$$
gcd(a,b) = c \in \mathbb F_c(a,b) \text{ where \(c|k, \forall k \in \mathbb F_c(a,b) \) }
$$

### Euclid's Algorithm

#### In words

1. Divide $a_1$ and $b_1$ ($\small a\geq b$) to obtain the quotient $q_1$ and remainder $r_1$
2. Divide $a_2 = b_1$ and $b_2 = r_1$ to obtain $q_2, r_2$
3. Continue $a_{n+1} = b_n, b_{n+1} = r_n, \frac{a_{n+1}}{b_{n+1}}=q_{n+1}, r_{n+1}$

#### Haskell implentation

```haskell
gcd2 :: Integer -> Integer -> Integer
gcd2 n m
    -- only divide big by small
  | n < m     = flip gcd2 n m
    -- begin recursion
  | otherwise = _gcd2 n m (remainder n m)
  where
    -- let p ? q = p divides q
    _gcd2 :: Integer -> Integer -> Integer -> Integer
    _gcd2 p q r
        -- if p ? q then return q (divisor)
      | p ? q              = q
        -- continue recursion
        -- perform divisor / remainder
      | otherwise          = _gcd2 q r (remainder q r)
```

Full code [here][haskell].

[haskell]: ./code/hs

## Lowest common multiple definition

### Common multiple

A common multiple of two numbers $a$ and $b$ is any integer-scaled product of the two numbers - a common multiple can be thought of as a number that has $a$ and $b$ as [common factors](#common-divisor).

$$
\text {Let common multiples = $\mathbb M_c(a,b) = \{ m:a|m $ and $b|m \}$  }
$$

### Lowest common multiple

The lowest common multiple of $a$ and $b$ is a number $m$ that is a factor of all other common multiples.

$$
lcm(a,b) = m \in \mathbb{M_c} \text{ where } m|k,\forall k\in\mathbb{M_c}(a,b)
$$

> ### **Aside**
>
> During tinkering with Haskell, I came to find that LCM is also equal to the product of $a$ and $b$ divided by the greatest common divisor of $a$ and $b$:
>
> $$ lcm(a,b) = \frac{ab}{gcd(a,b)} $$
>
> This seems to agree with [what Wolfram|Alpha says][w-alpha-says], but I wonder what the formal proof is for this...

[w-alpha-says]: https://www.wolframalpha.com/input/?i=ab%2F%28gcd%28a%2Cb%29%29

## Finding GCD and LCM using primes

### GCD with primes

The GCD is about **minimum** amount of factors that two numbers share.

By the [Fundamental Theorem of Arithmetic][fta], any number can be expressed as a product of primes:

$$
n = p_0^{N_0},p_1^{N_1},p_2^{N_2},...,p_k^{N_k},...,
\\
\forall n,N \in \natnums,\forall p_k\in \mathbb P \tag{$\mathbb P$ = primes}
$$

Therefore GCD of two numbers minimises the exponent on each prime $e_n$:

$$
\begin{aligned}
a &= p_0^{A_0}p_1^{A_1}...p_n^{A_n}...\\
b &= p_0^{B_0}p_1^{B_1}...p_n^{B_n}..\\
\space \\
gcd(a,b) &= p_0^{E_0}p_1^{E_1}...p_n^{E_n}... \\
\text{where }E_n&=\min(A_n, B_n)
\end{aligned}
$$

[fta]: ./06fta

### LCM with primes

This is the same principle as above except that the exponent on each prime is maximised instead.

$$
\begin{aligned}
lcm(a,b) &= p_0^{E_0}p_1^{E_1}...p_n^{E_n}... \\
\text{where }E_n&=\max(A_n, B_n)
\end{aligned}
$$
