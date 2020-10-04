package Main.Sorts;

import java.util.ArrayList;

public class Merge<T> extends BaseSorter<T> {

  private double log(double x) {
    return Math.logN(2, x);
  }

  public Merge() {
    super();
  }

  public Merge(T[] ns) {
    super(ns);
  }

  @Override
  public ArrayList<T> sort() {
    int halves = (int) logN(array.size());

    for (int i = 0; i < halves; i++) {

    }
  }
}
