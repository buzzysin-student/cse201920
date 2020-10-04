public class Fork extends Tree {
  Tree l;
  Tree r;

  public Fork(Tree l, Tree r) {
    this.l = l;
    this.r = r;
  }

  @Override
  public void accept(Visitor v) {
    v.visit(this);
  }
}