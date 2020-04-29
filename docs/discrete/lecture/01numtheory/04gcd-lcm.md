# GCD and LCM <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./03modular
[next]: ./05primes
[index]: ./index

## Greatest common divisor definition

### Common divisor

A common divisor is any number that divides into any two (or more) numbers.

$$
\text {Let common factors := \(\mathbb F_c(a,b) \) = \{ $f$: \(f|a\) and \(f|b\) \}}
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

## Lowest common multiple definition

### Common multiple

### Lowest common multiple

## Finding GCD and LCM using primes
