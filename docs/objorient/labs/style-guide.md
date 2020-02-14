# Style Guide <!-- omit in toc -->

- [1. Project Structure](#1-project-structure)
- [2. Naming](#2-naming)
  - [2.1 Classes](#21-classes)
  - [2.2 Functions and methods](#22-functions-and-methods)

## 1. Project Structure

This is likely going to be handled by our [Supreme Overlords][overlords], so I won't put anything here for now.

## 2. Naming

### 2.1 Classes

2.1.1 All classes should be in `PascalCase`

2.1.2 All classes should be descriptive nouns, i.e. `Unicorn`,`Salesman`,`JavaDeveloper`

> 2.1.i `[Optional]` Try to comment/document functions/classes like so:

```java
/**
 * @class MyClass
 * @description An example class for GitHub Markdown
 */
 public class MyClass extends Example {
   /**
    * @constructor MyClass
    * @param {String} name The name of myClass instance
    * @param {int} version The version number, e.g. 1
    */
   public MyClass(String name, int version){
     // This is a call to the super method
     super("Example", 1);
   }

   /**
    * @method example
    * @description This is an example method
    */
    @Override
    private static void example() {

    }
 }
```

### 2.2 Functions and methods

2.2.1 All methods should be in `camelCase`

2.2.2 All methods should be verb words, or actions

[overlords]: https://en.wikipedia.org/wiki/Flying_Spaghetti_Monster
