package Test;

import java.util.ArrayList;

import Main.Sorts.*;
public class Test {

  public static Integer compareNumber(Integer n1, Integer n2) {
    return n1 > n2 ? n1 == n2 ? 0 : 1 : -1;
  }

  public static void test(BaseSorter<Integer> sort) {
    sort.sort();
    sort.show();
  }

  public static void main(String[] args) {
    Integer[] tests = new Integer[] { 9, 1, 8, 2, 7, 3, 6, 4, 5 };

    ArrayList<BaseSorter<Integer>> sorts = new ArrayList<BaseSorter<Integer>>();
    sorts.add(new Quick<Integer>(tests));
    sorts.add(new Merge<Integer>(tests));
    sorts.add(new Insertion<Integer>(tests));
    sorts.add(new Bubble<Integer>(tests));

    sorts.forEach(sort -> {
      sort.compare = Test::compareNumber;
      test(sort);
    });

  }
}