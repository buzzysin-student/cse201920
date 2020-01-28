[Up](../) | [Home](/) | [Index](./index.md)

# Why use Java ?

Because raisins. Objects and shit.

# Java Syntax

```java
/* somefile.java */

// Private classes are only visible
// in the file they are defined in
private class SomeClass {

  // When this class is *inherited* then 
  // it is not visible to the child object
  private String __hidden;

  /* Getter and setter methods */

  // Getters can allow *access* to hidden properties
  public String name() {
    return __hidden;
  }

  // Setters can allow *changing* hidden properties
  public void name(String n) {
    __hidden = n;
  }
}
```