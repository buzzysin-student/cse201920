package Main.Sorts;

@FunctionalInterface
public abstract interface ICanCompare<T1, T2> {
  abstract Integer apply(T1 t1, T2 t2);
}