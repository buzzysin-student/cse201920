# The Bridges of Konisburg <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./02correctness
[next]: ./index
[index]: ./index

- [Graphs and their structure](#graphs-and-their-structure)
- [Definitions](#definitions)
- [Properties of an Euler Walk](#properties-of-an-euler-walk)

## Graphs and their structure

![Konisberg](https://www.kidscodecs.com/wp-content/uploads/2013/11/puzzles-7-bridges-map-euler.jpg)

A graph $G=(\bold{V},\bold{E})$ is a pair, where $V(G)=\bold V$ is a set of vertices $\{v_0, v_1,...\}$ and $E(G)=\bold E$ is a set of pairs of vertices such that $\bold E = \{\{u,v\}: u,v \in \bold V, u \neq v\}$ (this is a stricter definition of graphs where no **loops** are allowed).

## Definitions

- A **WALK** is any sequence of vertices $W = v_0, v_1, ..$ such that any two consecutive vertices $\{v_i, v_{i+1}\} \in \bold E$
- An **EULER WALK** is a walk with the added restriction that every edge in $W$ may only appear exactly once.
- Two graphs $G_1=(\bold V_1, \bold E_1), G_2=(\bold V_2, \bold E_2)$ are supposed to be **EQUAL** when $\bold V_1=\bold V_2$ and $\bold E_1=\bold E_2$. This means the sets of vertices and edges need to be identical for two graphs to be exactly **equal** to one another.
- On the other hand, two graphs are **ISOMORPHIC** if there exists a bijection $f: \bold V_1 \rarr \bold V_2$ such that $\{f(u), f(v)\} \in \bold E_2$, if and only if $\{u,v\} \in \bold E_1$. This is written as $G_1 \simeq G_2$.
- The **NEIGHBOURHOOD** of a vertex $v$ in graph $G$ is the set of vertices $N_G(v)$ connected to $v$ by at least one edge. Formally $N_G(v)=\{w \in \bold V: \{v,w\} \in \bold E \}$
- The **DEGREE** of a vertex $v$ in graph $G$ is the number of incident edges on that vertex, $d_G(v)=|N_G(v)|$

## Properties of an Euler Walk

With an Euler walk $v_0,...,v_k$:

- If $v_0=v_k$, (start and end are the same) then every vertex has even degree since every vertex is visited and exited as the walk is performed
- If $v_0\neq v_k$, (start and end are different) then every vertex besides the start and end vertex $v_0$ and $v_k$ have even degree, and $v_0,v_k$ have odd degree.

By this token, the Bridges of Konisburg do not have a Euler Walk, since every vertex has odd degree.