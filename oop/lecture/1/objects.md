[Up](../) | [Home](/) | [Index](./index.md)

# What is an object ?

> An object combines both data and methods in a new single and UNIQUE identity - a **unique position in memory**

* Methods are **resposible for their own data**.
* Objects can **communicate** with other objects.
* Objects can **expose (and hide)** informations to other objects.

## What is the difference between a class and an object?

* Classes act as a blueprint for creating an object.
* Classes are building blocks for small and compact code components.
* Classes can be reused and combined with other classes.

**Objects are INSTANCES of classes.**

# Class constructors

CLasses in java has a special method called the **CONSTRUCTOR** method. Example:

```java
// Robot.java

class Robot {
  String name;
  int numLegs;
  float powerLevel;
  
  // Constructor
  Robot(String name) {
    this.name = name;
    this.numLegs = 2;
    this.powerLevel = 0.2f;
  }
}

// RobotWorld.java

class RobotWorld {
  
}
```