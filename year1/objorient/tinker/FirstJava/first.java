class FirstJava {

  public static enum Comparison {
    LESS, EQUAL, GREATER;
  }

  public static Comparison myComparison(int x, int y) {
    var diff = x - y;
    return diff > 0 /*  */
        ? Comparison.GREATER
        : diff == 0 /*  */
            ? Comparison.EQUAL
            : Comparison.LESS;
  }

  public static void main(String args[]) {
    var input = 10;
    var actual = 10;

    switch (myComparison(10, 10)) {
      case GREATER:
        System.out.println("Input is bigger");
        break;
      case LESS:
        System.out.println("Input is smaller");
        break;
      default:
        System.out.println("Input is equal to Actual");
        break;
    }

  }
};