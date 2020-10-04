# Introduction to Linear Circuits <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./02geometry
[next]: ./04hyperbolic
[index]: ./index

- [Ohm's Law](#ohms-law)
- [Resistance and Conductance](#resistance-and-conductance)
- [Active/Passive Elements](#activepassive-elements)
- [Nodes, branches and loops](#nodes-branches-and-loops)
- [Series and parallel resistance](#series-and-parallel-resistance)

## Ohm's Law

Ohm's Law is the principle that the voltage difference across an elements terminal is proportional to the current going through it:

![fn](https://latex.codecogs.com/svg.latex?V=IR)

In other words, the constant of proportionality _R_ is the resistance of the element.

Additionally, the resistance of a conductive material can be defined as:

- proportional to the resistivity of the material, _rho_
- the length of the material, _l_
- the cross-sectional area of the material, _A_.

This yields:

$R=\rho \frac{l}{A}$

## Resistance and Conductance

Conductance is defined as the inverse of Resistance:

![fn](https://latex.codecogs.com/svg.latex?G=\frac{1}{R})

## Active/Passive Elements

An active element is a type of element that supplies a circuit with power. A passive element is the kind of element that dissipates power.

With the passive sign convention, active elements have a voltage increase in the same direction as the current, whereas passive elements will have a voltage drop in the same direction as the current through it.

## Nodes, branches and loops

A branch represents an element.

In circuits, a node is a point where terminals of different branches meet..

A loop is a path that starts and ends at the same node without repeating nodes.

## Series and parallel resistance

Elements are in series if they both:

- connected sequentially end-to-end
- ...and therefore carry the same current

Elements are in parallel if they:

- are connected to the same pair of terminals
- ...and therefore have the same voltage difference
