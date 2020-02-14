# Random variables (part 2) <!-- omit in toc -->

[Previous part](./randomvars.md)

- [Discrete and continuous random variables](#discrete-and-continuous-random-variables)
- [Combinations of random variables](#combinations-of-random-variables)
- [Cumulative distribution](#cumulative-distribution)
- [Measures of location](#measures-of-location)
  - [Mean](#mean)
  - [Median](#median)
  - [Mode](#mode)

## Discrete and continuous random variables

A continuous random variable describes a sample set ![#f1]

## Combinations of random variables

Consider the following random variables:

![fn](<https://latex.codecogs.com/svg.latex?\text{Throwing die n}:=D_n={1,2,3,4,5,6}}>)

![fn](<https://latex.codecogs.com/svg.latex?\text{Throwing a coin}:=C={H,T}}>)

There is the situation where:

- The same die is thrown twice
- Two die are thrown
- A die and a coin are thrown

## Cumulative distribution

The cumulative distribution function of a random variable is the cumulative sum of probabilities up to a point in the sample space:

![fn](<https://latex.codecogs.com/svg.latex?F_X(x)=\sum_x P(X\leq x)>)

## Measures of location

### Mean

The mean is also called the expected value of the random variable, i.e. what does the average value tend to if many observations were made? The mean is also often denoted by the Greek letter ![fn](https:/latex.codecogs.com/svg.latex?\mu).

Definition - discrete:

![fn](<https://latex.codecogs.com/svg.latex?E(X)=\mu:=\sum_x xP(X=x)>)

or the sum of the product of the probability function and the random variable.

Definiton - continuous:

![fn](<https://latex.codecogs.com/svg.latex?E(f(x))=\mu:=\int_a^b xf(x)dx\text{ where }x\in[a,b]>)

### Median

The median is the "halfway" point in a distribution - which outcome is expected to be exactly in the middle.

Definition:

![fn](<https://latex.codecogs.com/svg.latex?\text{Median}=x:P(X\leq x)=P(X\geq x)=0.5>)

### Mode

The mode is simply the most frequent event in the set of observations, simply defined as:

![fn](https://latex.codecogs.com/svg.latex?\text{Mode}=\text{max})

[Next part](./05randomvars.md)
