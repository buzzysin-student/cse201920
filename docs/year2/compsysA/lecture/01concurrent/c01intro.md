# Introduction to Concurrency <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./
[next]: ./c02concurrent
[index]: ../index

- [Concept](#concept)
- [Concurrency vs. Paralellism](#concurrency-vs-paralellism)
- [Comparing *Go* with other languages](#comparing-go-with-other-languages)

## Concept

There are many real-life parallels to concurrency in programming, such as managing systems of traffic, modelling brownian motion or even the process that goes on within the human brain. What these things have in common are that thery are **connected**, **related** and **interdependent** processes.

Programming concurrently aims to solve the problems that would otherwise be inefficient as a sequential program.

## Concurrency vs. Paralellism

Disamiguation: 

- Concurrency describes **logically** simultaneous processing
- Parallelism describes **physically** simultaneous processing

This is backed up by the fact that although the **Go** programming language can run tasks in parallel, this does not mean that multiple cores/threads are being used per-se.

Hence, using multiple cores solves the problems that can be addressed using physical parallelism, but using a concurrent programming language addresses problems that can be solved using logical parallelism.

## Comparing *Go* with other languages

While languages like C, C# and Java are capable of concurrent interaction **synchronised I/O operations on shared memory**, the control of the concurrency itself is a factor of the programmer's design (code writing) choices.

However, with Go, **messages** are exchanged on **channels**, concurrent interaction can be written without necessarily paying mind to shared memory.