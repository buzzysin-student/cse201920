# Number bases <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./01numbersets
[next]: ./02searches
[index]: ./index

## Binary

Binary is the represention of numbers in such a way that each place value in the number is represented by a $0$ or a $1$. This has the effect of making each place value a power of two: $..., 2^2, 2^1, 2^0$

### Binary Conversion

To convert from binary to decimal, add - from right to left - the product of the digit and the place value:

Example: 110101

| $2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| ----- | ----- | ----- | ----- | ----- | ----- |
| 1     | 1     | 0     | 1     | 0     | 1     |

$... = 32 + 16 + 4 + 1 = 53$

So $110101_2 = 53_{10}$

### Two's comlpement

Two's complement is a method that allows negative numbers to be expressed in binary in such a way that the arithmetic is still valid (i.e. carrying numbers, cancelling). This is done by considering the leading significant digit to be negative. This has the effect of adding positive numbers to a large negative number.

Example: 110101

| $-2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| ------ | ----- | ----- | ----- | ----- | ----- |
| 1      | 1     | 0     | 1     | 0     | 1     |

$... = -32 + 16 + 4 + 1 = -11$

## Octal

The idea of octal is much the same to that of binary and decimal in that each digit is represented by numbers from 0 up to 7, and each value is a power of 8.

### Octal Conversion

To convert from decimal to octal, divide by 8 repeatedly and take note of the remainders.

Example: 53

$$
\begin{aligned}
53 \div 8 &= 6, \{ r = 3 \} \\
 6 \div 8 &= 0, \{ r = 6 \} \\
53_{10}   &= 63_8
\end{aligned}
$$

## Hexadecimal

Once again, the idea of hexadecimal is the same as that of binary and octal, with the exception that since we do not have any single digit representation for numbers above 10, we use the first 6 letters of the alphabet.

$$
10 = A \\
11 = B \\
12 = C \\
13 = D \\
14 = E \\
15 = F
$$

### Hexadecimal conversion

To convert from decimal to hexadecimal divide by 16 repeatedly and track the remainders.

Example: 53

$$
\begin{aligned}
53 \div 16 &= 3, \{ r = 5 \} \\
 3 \div 16 &= 0, \{ r = 3 \} \\
53_{10}    &= 35_{16}
\end{aligned}
$$

## Other conversions

* Binary - Octal
  * Group binary into sets of 3 and evaluate to octal
  * $110101_2 \rarr 110_2,101_2 \rarr 65_8$
  * $65_8 \rarr 110_2, 101_2 \rarr 110101_2$
* Binary - Hexadecimal
  * Group binary into sets of 4 and evaluate to hexadecimal
  * $(00)110101_2 \rarr 0011_2,0101_2 \rarr 35_{16}$
  * $35_{16} \rarr 0011_2, 0101_2 \rarr (00)110101_2$

