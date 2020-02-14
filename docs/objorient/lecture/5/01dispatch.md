# Polymorphism <!-- omit in toc -->

- [Code duplication](#code-duplication)
- [Dynamic dispatch](#dynamic-dispatch)
  - [Single dynamic dispatch](#single-dynamic-dispatch)
  - [Multiple dispatch](#multiple-dispatch)

## Code duplication

To avoid code duplication, define a parent class that defines attributes and methods common to child classes.

```java
public abstract class Mammal {
  // Children should have this method, but
  // children can individually define behaviour
  public abstract makeNoise();
}

public class Dog extends Mammal {
  ...
}

public class Cat extends Mammal {
  ...
}
```

## Dynamic dispatch

### Single dynamic dispatch

When an overridden method is called via reference, the method is based on the type of the object referenced, not the reference type.

```java
...
Mammal cat = new Cat();
Mammal dog = new Dog();
...
```

If a dynamic dispatch decision cannot be made at compile time, then method resolution is made at runtime.

**Remember that call parameters are treated as static objects, not references to objects.**

### Multiple dispatch

This is the resolution of a method name based on more than one type.

Example 1 - using named methods

```java
// Main.java
public static void main(String [] args) {
  Mammal d = new Dog();
  Mammal c = new Cat();

  c.makeNoise(d);
  // Prints "SCREECH!" to console terminal
}
// Dog.java
...
public void makeNoise(Mammal m) {
  m.makeNoise(this);
}
// Cat.java
public void makeNoise(Dog d) {
  System.out.println("SCREECH!")
}
```
