public class Odd extends HasParity {
  Integer n;

  Odd(int n) {
    assert (n + 1) % 2 == 0;
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

  public Odd add(Even e) {
    return new Odd(this.n + e.n);
  }

  public Even add(Odd o) {
    return new Even(this.n + o.n);
  }

  public Even mul(Even e) {
    return new Even(this.n * e.n);
  }

  public Odd mul(Odd o) {
    return new Odd(this.n * o.n);
  }
}