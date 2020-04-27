# Exp and Normal Distributions <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./02geometry
[next]: ./04hyperbolic
[index]: ./index

- [Exponential distribution](#exponential-distribution)
  - [Definition of Exponential](#definition-of-exponential)
  - [Properties of Exponential](#properties-of-exponential)
    - [Link with Poisson distribution](#link-with-poisson-distribution)
    - [Mean of Exponential](#mean-of-exponential)
    - [Variance of Exponential](#variance-of-exponential)
- [Normal distribution](#normal-distribution)
  - [Definition of Normal](#definition-of-normal)
  - [Properties of Normal](#properties-of-normal)
  - [Converting to Normal](#converting-to-normal)
  - [Central Limit Theorem](#central-limit-theorem)

## Exponential distribution

What is the CRV that describes the time between two random events?
This is what the Exponential distribution is for.

### Definition of Exponential

If an event happens at time $t = 0$.

$\text{Assume that the p.d.f. for time until the next event is }F(t)$

$\text{Let the probability that the event has not happened be }G(t) = 1 - F(t)$

$\text{Then }G(t+\Delta t)=G(t)(1-\lambda \Delta t) [\text{differential equation}]$

$G'(t)=-\lambda G(t) \text{ since }G(0) = 1$

$\text{So }F(t) = 1 - e^{-\lambda t}\text{ and } f(t) = \lambda e^{-\lambda t}$

### Properties of Exponential

#### Link with Poisson distribution

TODO:

#### Mean of Exponential

The mean is given by:

$\mu=E(X)=\frac{1}{\lambda}$

#### Variance of Exponential

The mean is given by:

$\mu=E(X)=\frac{1}{\lambda}$

## Normal distribution

### Definition of Normal

The p.d.f of the normal distribution is as follows:

$\large f(x)=\frac{1}{\sigma \sqrt{2\pi}}e^{-\frac{1}{2\sigma^2}(x-\mu)^2}$

### Properties of Normal

The normal distribution is symmetric, so it has the property that the mean equals the median and the mode.

### Converting to Normal

$\text{If }X \sim N(\mu,\sigma^2) \text{ then }$

$Z = \frac{x-\mu}{\sqrt{\sigma^2}} \sim N(0,1)$

### Central Limit Theorem

