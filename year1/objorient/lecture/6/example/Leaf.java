public class Leaf extends Tree {
  int value;

  public Leaf(int value) {
    this.value = value;
  }

  @Override
  public void accept(Visitor v) {
    v.visit(this);
  }
}