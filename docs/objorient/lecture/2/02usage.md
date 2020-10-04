# The keywords <!-- omit in toc -->

- [`new`](#new)
- [`static`](#static)
- [`public`](#public)
- [Typical program](#typical-program)

## `new`

This keyword tell java to create an object on the [heap](../3/lifecycle#the-heap-and-the-stack)

## `static`

The `static` keyword allows the following behaviour:

- It does not need to be bound to a class instance (i.e. no need to use `new`)
- It is generally not used unless absolutely necessary in OOP

## `public`

The public keyword signifies that the methods/properties are bound to the instance and not the class, i.e. `new` is needed for them to be used.

## Typical program

```java
// Adder.java
public class Adder {
  public int sum;

  public void add(int summand){
    sum += summand;
  }
}

// Main.java
// ... imports ...

public class Main {
  public void main(String args[]){
    // Create the new object
    Adder adder = new Adder();
    // An example for loop
    for (String arg: args) {
      // Add the integers passed as a string in the program
      adder.add(Integer.parseInt(arg)
      /* Turn the string into an integer*/);
    }

    // NOTE: We are accessing the static `parseInt` member
    // of the `Integer` class

    // Print the running sum
    System.out.println(adder.sum);
  }
}
```
