package Main.Sorts;

import java.util.ArrayList;

public class BaseSorter<T> extends ICanSort<T> {
  public ArrayList<T> array;
  public ICanCompare<T, T> compare;

  public BaseSorter() {
    this.compare = (n1, n2) -> {
      return 0;
    };
    this.array = new ArrayList<T>();
  }

  public BaseSorter(T[] ns) {
    this.compare = (n1, n2) -> {
      return 0;
    };
    this.array = new ArrayList<T>();
    for (T i : ns) {
      this.array.add(i);
    }
  }

  public ArrayList<T> sort() {
    System.out.println("Not implemented");
    return array;
  }

  public void show() {
    System.out.printf("[ ");
    array.forEach(n -> {
      System.out.printf("%s ", n.toString());
    });
    System.out.printf("]\n");
  }
}