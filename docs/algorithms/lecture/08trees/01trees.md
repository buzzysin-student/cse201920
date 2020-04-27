# Recursion trees <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[next]: ./index
[prev]: ./index
[index]: ./index

- [Tree definition](#tree-definition)
  - [Other definitions](#other-definitions)
  - [Properties of trees](#properties-of-trees)
  - [Binary trees](#binary-trees)
- [Order of tree height](#order-of-tree-height)

> Note: trees will be denoted by $T$, nodes will be denoted by $v_k$, edges will be denoted by $e_k$

## Tree definition

A **node** is a point on a graph.

An **edge** is a connection between exactly two nodes.

A **tree** is a type of graph that can be represented using the following property:

$$
T_n \text{ is a tree with } n \text { nodes if } \\
T_n = (V, E) \text{ where } \\
V = \left\{ v_1, v_2, \cdots, v_n \right\} (|V|=n) \\
E=\left\{e_1, e_2, \cdots, e_{n-1}\right\} (|E|=n-1)
$$

A **rooted tree** is a type of tree such that there is a **root** node, i.e. a node that is the rest of the tree "descends" from.

### Other definitions

For a rooted tree:

A **parent** of a node $v$ is the incident node closest to the root of the tree.

A **child** of a node $v$ is its neighbours except its parent (i.e. incident nodes furthest from the root).

The **height** of a tree $T$ is the length of the longest path from the root node to a node.

The **degree** of a a node $v$, denoted as $\deg v$ is the number of edges incident on that node.

### Properties of trees

Every new node adds an edge, and there is always 1 less node per edge on the graph, so we have this relation.

$$E=V-1$$

Every edge contributes 2 to the degree of the tree, so the following holds:

$$
\sum_{v \in V}\deg v = 2 |E| = 2(n-1)
$$

### Binary trees

A **$k$-ary tree** is a type of tree such that the children of a given node $v$ is always equal to $k$. A binary tree is a $k$-ary tree where $k=2$.

A $k$-ary (i.e. binary, ternary,...) tree is **full** if every internal node has exactly $k$ children.

A $k$-ary tree is **complete** when every layer except the last is completely filled, and the last level is filled from left to right.

A **perfect** $k$-ary tree is a tree where every layer is filled completely. A perfect tree has $k^{l-1}$ nodes. The number of layers is also the height of the tree.

## Order of tree height

The order of perfect $k$-ary trees can be given with regard to its height, $l$:

$$
\text{Nodes = }\sum_{i=0}^{l-1} k^i = \frac{k^l-1}{k-1}
$$

So for a tree of size $n$, $T_n$, the order of the height can be derived:

$$
\begin{aligned}
  v &= \frac{k^l-1}{k-1} \\
  v (k - 1) &= k^l - 1 \\
  l \log k &= \log (v (k - 1) + 1) \\
  l \text{ (height) } &= \log_k(v (k-1) + 1) \\
  &= O(\log_k v) \space (k \text{ is constant})
\end{aligned}
$$
