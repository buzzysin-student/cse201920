# The Visitor Pattern <!-- omit in toc -->

- [Recaps](#recaps)
  - [Abstract classes](#abstract-classes)
  - [Subclasses](#subclasses)
- [Visitor pattern](#visitor-pattern)

## Recaps

### Abstract classes

An abstract class is a class that is purely conceptual and cannot be implemented - a good example is a Mammal class - this is because Human and Dolphin are instances of Mammal, however there cannot be such an instance of Mammal only. There is no "generic mammal".

> Note: it might be worth stating that an interface is a fully abstract class - an abstract class with fully abstract methods only.

### Subclasses

A subclass is a class that supports inheritance and polymorphism - i.e. it extends the behaviour of its parent class and can alter certain methods accordingly.

## Visitor pattern

A pattern is a way that objects interact with each other to achieve a goal. The visitor pattern is one such pattern.

With the visitor pattern, other objects are "accepted" into the class. The visitor pattern facilitates the addition of new operations to existing object structures without modifying those structures. A visitor class is created that implements all the appropriate specialisations.

The visitor needs to know the structure of the objects that it is going to work with. The object that is being visited, however, does not need to know the structure of the visitor. This is a form of dynamic dispatch.

Despite references having an abstract type when initialised, the type of the underlying object on the heap is resolved at runtime, so overloaded methods (of the visitor) are able to communicate with the object (the receiver) despite only seeing the abstract class type.
