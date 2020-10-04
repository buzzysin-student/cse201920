public abstract class AbstractDessertMaker extends AbstractChef {

  public AbstractDessertMaker(String name, int skill) {
    super(name, skill);
  }

  public void getEggs() {
    System.out.println("Trouver les oeufs");
  }

  public void getChocolate() {
    System.out.println("Il est interdit de manger le chocolat!");
  }

  public void doWhisk() {
    System.out.println("Agiter, agiter...");
  }
}