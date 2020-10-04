public class InterfaceDessertChef extends InterfaceChef implements RecipeGanache, RecipeSouffle {

  public InterfaceDessertChef(String name, int skill) {
    super(name, skill);
  }

  @Override
  public void doWhisk() {
    System.out.println("Agiter, agiter...");
  }

  @Override
  public void getChocolate() {
    System.out.println("Il est interdit de manger du chocolat!");
  }

  @Override
  public void getEggs() {
    System.out.println("En train de trouver les oeufs");
  }

  @Override
  public void makeSouffle() {
    this.getEggs();
    this.doWhisk();
    System.out.println("\nMade Fluffy Souffle\n");
  }

  @Override
  public void makeGanache() {
    this.getChocolate();
    this.doWhisk();
    System.out.println("\nMade Chocolate Ganache\n");
  }
}