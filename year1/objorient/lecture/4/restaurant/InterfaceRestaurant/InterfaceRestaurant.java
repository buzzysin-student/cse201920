import java.io.PrintStream;

public class InterfaceRestaurant {
  public static void main(String[] args) {
    PrintStream out = System.out;
    InterfaceDessertChef jean = new InterfaceDessertChef("Jean-Pierre", 1);
    out.println(jean.name);
    jean.makeGanache();
    jean.makeSouffle();
  }
}