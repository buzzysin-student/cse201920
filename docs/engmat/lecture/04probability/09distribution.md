# Exp and Normal Distributions <!-- omit in toc -->

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

If an event happens at time _t = 0_.

![fn](<https://latex.codecogs.com/svg.latex?\text{Assume that the p.d.f. for time until the next event is }F(t)>)

![fn](<https://latex.codecogs.com/svg.latex?\text{Let the probability that the event has not happened be }G(t) = 1 - F(t)>)

![fn](<https://latex.codecogs.com/svg.latex?\text{Then }G(t+\Delta t)=G(t)(1-\lambda \Delta t) [\text{differential equation}]>)

![fn](<https://latex.codecogs.com/svg.latex?G'(t)=-\lambda G(t) \text{ since }G(0) = 1>)

![fn](<https://latex.codecogs.com/svg.latex?\text{So }F(t) = 1 - e^{-\lambda t}\text{ and } f(t) = \lambda e^{-\lambda t}>)

### Properties of Exponential

#### Link with Poisson distribution

TODO:

#### Mean of Exponential

The mean is given by:

![fn](<https://latex.codecogs.com/svg.latex?\mu=E(X)=\frac{1}{\lambda}>)

#### Variance of Exponential

The mean is given by:

![fn](<https://latex.codecogs.com/svg.latex?\mu=E(X)=\frac{1}{\lambda}>)

## Normal distribution

### Definition of Normal

The p.d.f of the normal distribution is as follows:

![fn](<https://latex.codecogs.com/svg.latex?\large f(x)=\frac{1}{\sigma \sqrt{2\pi}}e^{-\frac{1}{2\sigma^2}(x-\mu)^2}>)

### Properties of Normal

The normal distribution is symmetric, so it has the property that the mean equals the median and the mode.

### Converting to Normal

![fn](<https://latex.codecogs.com/svg.latex?\text{If }X \sim N(\mu,\sigma^2) \text{ then }>)

![fn](<https://latex.codecogs.com/svg.latex?Z = \frac{x-\mu}{\sqrt{\sigma^2}} \sim N(0,1)>)

### Central Limit Theorem

