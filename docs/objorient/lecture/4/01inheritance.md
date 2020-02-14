# Inheritance <!-- omit in toc -->

- [Definition of inheritance](#definition-of-inheritance)
- [Recap](#recap)
- [Extending a class](#extending-a-class)
  - [The `extends` keyword](#the-extends-keyword)
  - [The `@Override` decorator](#the-override-decorator)
- [The risks of class extension](#the-risks-of-class-extension)
  - [Example](#example)
- [Summative example](#summative-example)

## Definition of inheritance

In object-orientation, inheritance is one of the pillars, and it describes the process by which classes form relationships - different types of relationships

A class can [`extend`](#the-extends-keyword) a parent class so that it alters the behaviour of its parent class.

Without inheritance, classes in `java` would be free-standing units developed from the ground up.

## Recap

- Objects belong to their respective classes
- Classes act like types - object references are given a type during declaration

  ```java
  ...
  Robot /* type */ newRobot /*reference*/ = new Robot("Wall-E");
  ...
  ```

## Extending a class

### The `extends` keyword

Imagine a class that has all methods and properties that is needed, except a few methods are necessary, or has different behaviour.

There are 2 ways that a class can change the behaviour of a method:

1. Overloading [(Polymorphism)][polymorphism]
2. Overriding

### The `@Override` decorator

The difference between overloading and overriding is **quite important** as if the programmer intends to change the behaviour of a method, **`@Override`** is required, otherwise a copy of the method with the signature is created, which is 

## The risks of class extension

Inheritance should only be used for specialisation, i.e. when there is a "is-a" relationship between classes, not a "has-a" relationship.

### Example

Has-a relationship: this is not correct inheritance :x:

```java
-> Motor
  -> Robot extends Motor
```

Is-a relationship: this is correct inheritance :heavy_check_mark:

```java
-> Machine
  -> Robot extends Machine
```

## Summative example

```java
// Robot.java
public class Robot {
  // Has methods `talk`, `charge` and `constructor`
}

// TranslationRobot.java
public class TranslationRobot
  extends /* inherits methods */ Robot {
    // Has mehtods `talk`, `charge` and  `construtor`

    @Override
    void charge(float amount) {
      // This will change the behaviour of the
    }
}
```

[polymorphism]: ./