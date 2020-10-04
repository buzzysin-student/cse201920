import java.io.PrintStream;

public class AbstractRestaurant {

  public static void main(String[] args) {
    PrintStream out = System.out;
    AbstractDessertChef remy = new AbstractDessertChef("Remy", 1);
    out.println(remy.name);
    remy.makeGanache();
    remy.makeSouffle();
  }
}