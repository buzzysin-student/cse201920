package Main;

import java.util.ArrayList;

import Main.Sorts.BaseSorter;
import Main.Sorts.ICanCompare;
import Main.Sorts.Quick;

public class Main {

  public static void main(String[] args) {

    ICanCompare<Number, Number> comparison = (n1, n2) -> {
      return n1.doubleValue() > n2.doubleValue() ? 1 : n1 == n2 ? 0 : -1;
    };

    ArrayList<Number> ns = new ArrayList<Number>();
    for (String arg : args) {
      ns.add(Double.parseDouble(arg));
    }

    BaseSorter<Number> sorter = new Quick<Number>();
    sorter.array = ns;
    sorter.compare = comparison;

    sorter.sort();
    sorter.show();
  }
}