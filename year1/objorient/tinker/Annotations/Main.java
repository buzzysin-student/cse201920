import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

public class Main {

  @Retention(RetentionPolicy.RUNTIME)
  @interface TestAnnotation {
    Class<?>[] value() default {};
  }

  public class Adder {
    public int sum = 0;

    public Adder(int a, int b) {
      this.sum = a + b;
    }

    int create(int a, int b) {
      return a + b;
    }
  }

  @TestAnnotation({ Adder.class })
  public class TestClass {
  }

  public static void main(String[] args) throws Exception {
    System.out.println("Starting program ...");
    System.out.println("====================\n");
    for (var annotation : TestClass.class.getAnnotations()) {
      System.out.println(((TestAnnotation) annotation).value()[0].getConstructors());
      System.out.println(((Adder)(((TestAnnotation) annotation).value()[0].getConstructors()[0].newInstance(new Main(), 1, 2))).create(3, 4));
    }
  }
}