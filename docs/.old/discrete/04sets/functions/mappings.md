# Functions

A function is a relation that satisfies:

$\text{Given } f:A\rightarrow B,\text{then}$

$\forall x\in{A}, \exists y \in{B}:f(x)=y$

> For all x, there exists some y such that f(x) = y

$(x,y)\in f \rightarrow (x,z)\notin f \text{ where } y\neq z$

> There is only a single value, y for any given input x (i.e. z does not exist as it is another output for f(x))

## Classification of functions

$\text{Given }f:A\rightarrow B,\text{then}$

### Injective

An injective function is one such that there is **exactly one** output for every input, but not every output has an input.

#### Example

$f(x)=x^2\text{ where }x\geq0$

```haskell
A(Reals+) -> B(Reals+)
1     -> 1
2     -> 4
...
+n    -> n^2
```

**Remember** that a function is defined such that y values are unique for any x, so negative values in this definition is not allowed, since 2 and -2 map to 4.

---

### Surjective

A surjective function is one such that there is **at least one** input for every output, i.e. there is not a way to distinguish an input given an output

#### Examples

$f(x)=x^2,\underline{x\in\mathbb{R},f(x)\in\mathbb{R^+}}$

The domain of the function _f_ is underlined to show that this function is **surjective for all positive real values** of _f_, but **not injective** in this range.

```haskell
A(Reals) -> B(Reals+)
1     -> 1
(-1)  -> 1
2     -> 4
(-2)  -> 4
...
+/- n -> n^2
```

$f(x)=2x,x \in \mathbb{Z} \wedge \underline{f(x) \in { 2k : k \in \mathbb{Z}}}$

This one is a little more difficult to see at first glance that it is surjective - this is surjective because of the **codomain restriction** on _f(x)_. Since _f(x)_ can only be even integers, this means that every even integer has a single input _x_ in the integers. If the codomain was the set of _all_ integers, then this would not be surjective as the _odd numbers_ in the codomain will not be mapped.

```haskell
-- Example where codomain is
A(Ints) -> B(Evens)
1 -> 2
2 -> 4
...
n -> 2n
```

---

### Bijective - both injectve and surjective

This one is easy - there is one input for every output and vice-versa. This is also called a **one-to-one** function.

### Exercise 2.1

<span align="center">

</span>

Classify the following functions given $f(x) = x^2$

a) $f:\mathbb{N}\rightarrow\mathbb{N}$

> Answer: injective
>
> Explanation: there exists some members of _f(x)_ where _f(x)_ is not in _N_, i.e. all of the non-squares 2,3,5,6,7,8,10,...

b) $f:\mathbb{R}\rightarrow\mathbb{R}$

> Answer: neither
>
> Explanation: every

c) $f:\mathbb{R^+}\rightarrow\mathbb{R^+}$

d) $f:\mathbb{R}\rightarrow\mathbb{R^+}$

e) $f:\mathbb{Z}\rightarrow\mathbb{Z}$

---

<span align="center">

![image](https://calculushowto.com/wp-content/uploads/2018/12/surjective-or-injective-3.png)

> Credit: Calculus How To

</span>
