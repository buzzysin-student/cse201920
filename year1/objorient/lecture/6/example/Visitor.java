public abstract class Visitor {
  public abstract void visit(Fork f);
  public abstract void visit(Leaf l);

  public class SumVisitor extends Visitor {
    int sum;

    @Override
    public void visit(Fork f) {
      f.l.accept(this);
      f.r.accept(this);
    }

    @Override
    public void visit(Leaf l) {
      this.sum += l;
    }
  }
}