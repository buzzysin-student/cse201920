package Main.Sorts;

import java.util.ArrayList;

public class Merge<T> extends BaseSorter<T> {

  private double logN(double n, double x) {
    return Math.log(x) / Math.log(n);
  }

  public Merge() {
    super();
  }

  public Merge(T[] ns) {
    super(ns);
  }

  @java.lang.Override
  public ArrayList<T> sort(){
    int halves = (int)logN(2, array.size());
    for (int i = 0; i < halves; i ++) {

    }
    return array;
  }
}