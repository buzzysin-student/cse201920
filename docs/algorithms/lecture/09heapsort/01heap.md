# What is a Heap <!-- omit in toc -->

[~~Previous Chapter~~][prev] | [~~Next Chapter~~][next] | [Chapter Contents][index]

[next]: ./index
[prev]: ./index
[index]: ./index

## Heaps from arrays

### Definition of Heap

A heap is a binary tree where each node contains children that are less than the value in that node.

We can build an unordered heap by iterating through the array.

This is not a heap as 3 is less that 8, for example. The algorithm to make a heap is as follows:

```python
algorithm build_heap

Require an integer tree `t` of size `n`

assume t is perfect
```
