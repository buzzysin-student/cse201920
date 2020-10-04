import java.util.List;
import java.util.Collection;
import java.util.ArrayList;

public class Exercise1 {

  public static List<Integer> getTestList(Integer[] ints) {
    List<Integer> testList = new ArrayList<Integer>();
    for (Integer i : ints) {
      testList.add(i);
    }
    return testList;
  }

  public static void showList(List<Integer> list) {
    for (Integer n : list) {
      System.out.printf("%d ", n);
    }
    System.out.println();
  }

  public static void main(String[] args) {
    List<Integer> testList = getTestList(new Integer[] { 4, 3, 2, 1 });
    List<Integer> resultList = questionOne(testList);
    showList(resultList);
    questionTwo();
  }

  /**
   * TODO: Exercises!
   */

  // ? Ex 1, Q1
  public static List<Integer> questionOne(List<Integer> arr) {
    // * Variable for size
    int size = arr.size();

    // * For each item in the List
    for (int i = 0; i < Math.floorDiv(size, 2); i++) {
      // * Set aside the item to be copied
      int tempInt = arr.get(i);
      int indexToSwap = size - (i + 1);

      // * Swap the indices
      arr.set(i, arr.get(indexToSwap));
      arr.set(indexToSwap, tempInt);
    }

    return arr;
  }

  // ? Ex 1, Q2
  public static void questionTwo() {
    System.out.println("Sub-type polymorphism in Java\n" + ///
        "========\n" + ///
        "A subtype polymorphism example is when a child class inherits\n" + ///
        "and changes the behaviour of a parent class method.\n" + ///
        "\n" + ///
        "When an object is referenced as the parent class but uses the\n" + ///
        "constructor of the child class."); ///
  }
}