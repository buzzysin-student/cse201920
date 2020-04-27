# Conditional Probability <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./
[next]: ./
[index]: ../index

## Events based on other events

Conditional probability asks the question where we calculate the outcome of an event based on previous events. We use the $A|B$ operator, pronounced a A _given_ B, to represent the probability of $A$ given that $B$ has happened.

## Calculation

Assume that we have a set of playing cards, $C$. What is the probability that a card picked is a spade suit given that it is a 6?

Here are different related subsets of our sample space:

$$
\begin{aligned}
  C_\spades &= \left\{1\spades,2\spades,\cdots,K\spades \right\} \\
  C_6 &= \left\{6\spades, 6\clubs, 6\hearts, 6\diamonds \right\} \\
\end{aligned}
$$

We can re-formalise the question as follows:

$$
P(C=\spades | C=6) = \frac{P(C\in C_{\spades}\cap C\in C_6)}{P(C\in C_6)}
$$

This also looks like:

$$
P(C=\spades | C=6) = \frac
  {\left|\left\{ 6\spades\right\} \right|}
  {\left|\left\{6\spades, 6\clubs, 6\hearts, 6\diamonds \right\} \right|}
$$

Or similarly:

$$
P(A|B) = \frac{\text{Size of intersection of A and B}}{\text{Sample size of B}}
$$

Note that the intersection of $C_6$ and $C_\spades$ is $6\spades$, i.e. it is in both sets. It is easier here to see that $P(C=\spades | C=6) = 1/4$

Here is the general formula for a single conditional event:

$$
\begin{aligned}
  P(A|B) &= \frac{P(A\cap B)}{P(B)} \\
  &= \frac{\frac{1}{52}}{\frac{1}{13}} = \frac{13}{52} =\frac{1}{4}
\end{aligned}
$$
