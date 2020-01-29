# 2. O-notation

## Algorithm runtime

Runtime is a function that maps input length of data into an algorithm to the number of operations that an algorithm will execute. There are different types of runtime considerations:

* Best-case runtime
* Worst-case runtime
* Average-case runtime

The best function of runtime depends on the size of the input (i.e. depending on the input length n)

    ! TODO -> Example here

## Asymptotic complexity

For large n, constants in the calculation of the complexity function of an algorithm matter less and may be ignored.

For small n, most algorithms are quite fast anyway.

> Lemma:
> An increasing function f will grow asymptotically at

## Racetrack principle

If <img src="/algorithms/lecture/2/tex/cf684a82f3118429472c85a503f9e770.svg?invert_in_darkmode&sanitize=true" align=middle width=61.969361849999984pt height=24.65753399999998pt/> and <img src="/algorithms/lecture/2/tex/874da51160c673f5f63497bc4bff8366.svg?invert_in_darkmode&sanitize=true" align=middle width=157.7650833pt height=24.7161288pt/> then for every <img src="/algorithms/lecture/2/tex/eb9318a3110bc0432a4accb70d559bf9.svg?invert_in_darkmode&sanitize=true" align=middle width=18.94224584999999pt height=22.831056599999986pt/>, it holds that <img src="/algorithms/lecture/2/tex/b24c4be190b46d267f62df62d1a85dae.svg?invert_in_darkmode&sanitize=true" align=middle width=63.55238999999999pt height=24.65753399999998pt/>