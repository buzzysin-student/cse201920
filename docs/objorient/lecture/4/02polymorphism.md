# Polymorphism <!-- omit in toc -->

- [Definition](#definition)
  - [The good](#the-good)
  - [The bad](#the-bad)

## Definition

Every reference to an object can be a superclass of the class of the object. This can have useful and dangerous implications.

In code:

### The good



### The bad

```java
...
// References to objects are the same
Robot myrobot = new Robot("myRobot");
TranslationRobot francis = new TranslationRobot("Francis");
// Since Robot > TranslationRobot, this reference is valid
Robot anthony = new TranslationRobot("Handsome Anthony");

/** NOTE: EASTER EGG! Search `BLR apple product launch` */

/**
 * However, the reference to the object is treated
 * as the type of the reference
 *
 * This is because the compiler doesn't know that `guillaume`
 * is a reference to a TranslationRobot
 */
anthony.translate("Καλημέρα!"); // ERROR!
...
```
