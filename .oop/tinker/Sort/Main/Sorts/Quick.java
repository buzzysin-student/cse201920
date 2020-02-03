package Main.Sorts;

import java.util.ArrayList;

public class Quick<T> extends BaseSorter<T> {

  public Quick() {
    super();
  }

  public Quick(T[] ns) {
    super(ns);
  }

  private int pivotIndex() {
    return (int) Math.ceil((array.size() + 1) / 2);
  }

  private T pivot() {
    return array.get(pivotIndex());
  }

  @Override
  public ArrayList<T> sort() {
    if (array.size() <= 1)
      return array;

    T pivot = pivot();
    int index = pivotIndex();

    Quick<T> lt = new Quick<T>();
    Quick<T> gt = new Quick<T>();
    gt.compare = lt.compare = compare;

    ArrayList<T> result = new ArrayList<T>();

    for (int i = 0; i < array.size(); i++) {
      T n = array.get(i);
      if (compare.apply(n, pivot) < 1 && i != index) {
        lt.array.add(n);
      } else if (compare.apply(n, pivot) == 1 && i != index) {
        gt.array.add(n);
      }
    }

    result.addAll(lt.sort());
    result.add(pivot);
    result.addAll(gt.sort());

    array = result;

    show();

    return array;
  }
}