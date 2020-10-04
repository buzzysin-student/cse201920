
public class Critter {
  String Name;

  public Critter(String name) {
    this.Name = name;
  }

  public void poke() {
    System.out.println(this.Name + " got poked");
  }
}