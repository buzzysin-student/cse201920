# Probability distributions <!-- omit in toc -->

- [Bernoulli Distribution](#bernoulli-distribution)
  - [Definition of Bernoulli](#definition-of-bernoulli)
  - [Properties of Bernoulli](#properties-of-bernoulli)
    - [Mean of Bernoulli](#mean-of-bernoulli)
    - [Variance or Bernoulli](#variance-or-bernoulli)
- [Geometric Distribution](#geometric-distribution)
  - [Definition of Geometric](#definition-of-geometric)
    - [The Bernoulli process](#the-bernoulli-process)
    - [Geometric CDF](#geometric-cdf)
- [Binomial Distribution](#binomial-distribution)
  - [Definition of Binomial](#definition-of-binomial)
  - [Properties of Binomial](#properties-of-binomial)
    - [Mean of Binomial](#mean-of-binomial)
    - [Variance of Binomial](#variance-of-binomial)
- [Poisson distribution](#poisson-distribution)
  - [Definition of Poisson](#definition-of-poisson)
    - [_n_ large, _p_ small](#n-large-p-small)
  - [Properties of Poisson](#properties-of-poisson)
    - [Mean](#mean)
    - [Variance](#variance)

## Bernoulli Distribution

### Definition of Bernoulli

Let the probability of success be _p_.

Then the proabability of failure is _1 - p_

Let the random variable _X_ be _1_ on success and _0_ on failure.

The [probability function](03randomvars.md#the-probability-function) for this random variable is:

![fn](<https://latex.codecogs.com/svg.latex?\newline P_X(1) = P(X=1) = p\newline P_X(0) = P(X=0) = 1-p>)

This is one of the most simple distributions to calculate.

### Properties of Bernoulli

#### Mean of Bernoulli

![fn](<https://latex.codecogs.com/svg.latex? \mu = E(X) = \sum_{n=0}^{1}[n P_X(n)] = (0\times (1-p)) + (1\times p) = p>)

#### Variance or Bernoulli

![fn](<https://latex.codecogs.com/svg.latex?\newline \sigma^2 = E(X^2) - \mu^2 = \sum_{n=0}^{1}[n^2 P_X(n)] - p^2 \newline = (0^2\times (1-p)) + (1^2\times p) - p^2 = p(1-p)>)

## Geometric Distribution

### Definition of Geometric

#### The Bernoulli process

The Geometric Distrubution builds on the idea of the Benoulli distribution. It asks the question:

> How many trials, _X_, do I need before I get a success?

The answer is _n-1_ failures followed by 1 success:

![fn](<https://latex.codecogs.com/svg.latex? (1-p)\times(1-p)\times(1-p)\times...[n - 1 \text{ times}] \times p = p(1-p)^{n-1}>)

Therefore the probability function for the random variable _X_ is:

![fn](<https://latex.codecogs.com/svg.latex? P_X(n) = P(X=n) = p(1-p)^{n-1}>)

#### Geometric CDF

![fn](<https://latex.codecogs.com/svg.latex? F_X(n) = P(X\leq n) = 1- (1-p)^{n}>)

## Binomial Distribution

The binomial distribution asks the question

> How many sucesses, _X_, do I receive within _n_ trials?

In _n_ trials:

- There are _n!_ possible permutations of successes and failures
- There are _k!_ possible permutations of successes only
- There are _(n-k)!_ possible permutations of failures only

To avoid double-counting permutations, the binomial coefficient is formed:

![fn](<https://latex.codecogs.com/svg.latex?{{n}\choose{k}} = \frac{n!}{k!(n-k)!}>)

### Definition of Binomial

Given the above information, the probability density function for this random variable is:

![fn](<https://latex.codecogs.com/svg.latex?P_X(n) = P(X=n) = {n \choose k} \frac{n!}{k!(n-k)!}>)

### Properties of Binomial

#### Mean of Binomial

![fn](<https://latex.codecogs.com/svg.latex?\mu=E(X)=np>)

#### Variance of Binomial

![fn](<https://latex.codecogs.com/svg.latex?\sigma^2=E(X^2)-\mu^2=np(1-p)>)

## Poisson distribution

### Definition of Poisson

#### _n_ large, _p_ small

It is possible to derive the Poisson distribution of a random variable by considering the limits of _n_ and _p_ as _n_ tends to infinity and _p_ tends to zero:

![fn](<https://latex.codecogs.com/svg.latex?\text{Let }\epsilon=\frac{1}{n},\text{ and }\lambda=\frac{p}{\epsilon}>)

Then

![fn](<https://latex.codecogs.com/svg.latex?P(Y=k)=\lim_{\epsilon\rightarrow0}[{n \choose k}p^kq^{n-k}]>)

![fn](<https://latex.codecogs.com/svg.latex?=\lim_{\epsilon\rightarrow0}[\frac{1(1-\epsilon)...(1-\epsilon(k-1))}{k!}]\lambda^k \times\lim_{\epsilon\rightarrow0}[(1-\epsilon\lambda)^\frac{1}{\epsilon}]\times \lim_{\epsilon\rightarrow0}[(1-\epsilon\lambda)^{-k}]>)

... and because of some maths magic...

![fn](<https://latex.codecogs.com/svg.latex?=\frac{1}{k!}\times e^{-\lambda} \times 1>)

So:

![fn](<https://latex.codecogs.com/svg.latex?P(Y=k)=\frac{\lambda^k e^{-\lambda}}{k!}>)

### Properties of Poisson

#### Mean

Definition of the mean:

![fn](<https://latex.codecogs.com/svg.latex?\mu = E(X) = \sum_{k=0}^{\infty}kP(X=k)>)

Substitute the definiton of the Poisson Distribution:

![fn](<https://latex.codecogs.com/svg.latex?=\sum_{k=0}^{\infty} \frac{k \lambda^k e^{-\lambda}}{k!}>)

Factor out lambda and exponential term to rewrite sum:

![fn](<https://latex.codecogs.com/svg.latex?=\sum_{k=1}^{\infty} \frac{\lambda^{k} e^{-\lambda}}{(k-1)!}=\lambda e^{-\lambda}\sum_{k=0}^{\infty}\frac{\lambda^{k}}{k!}>)

Use the summation identity for the exponential:

![fn](<https://latex.codecogs.com/svg.latex?=\lambda e^{-\lambda}\times e^{\lambda} = \lambda>)

#### Variance
