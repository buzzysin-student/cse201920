public class Main {
  public static void main(String[] args) {
    Even even = new Even(2);
    Odd odd = new Odd(4);

    assert even.add(odd) instanceof Odd;
    assert odd.add(even) instanceof Odd;
    assert even.add(even) instanceof Even;
    assert odd.add(odd) instanceof Even;

    assert even.mul(even) instanceof Even;
    assert even.mul(odd) instanceof Even;
    assert odd.mul(even) instanceof Even;
    assert odd.mul(odd) instanceof Odd;
  }
}