public class Even extends HasParity {
  Integer n;

  Even(int n) {
    assert n % 2 == 0;
    this.n = n;
  }

  public String toString() {
    return this.n.toString();
  }

  public boolean equals(Object obj) {
    return this.n.equals(obj);
  }

  public int hashCode() {
    return this.n.hashCode();
  }

  public Even add(Even e) {
    return new Even(this.n + e.n);
  }

  public Odd add(Odd o) {
    return new Odd(this.n + o.n);
  }

  public Even mul(HasParity e) {
    return new Even(this.n * e.n);
  }
}