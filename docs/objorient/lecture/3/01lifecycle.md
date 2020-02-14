# Object's Lifecycle <!-- omit in toc -->

- [Recap](#recap)
- [The Heap and the Stack](#the-heap-and-the-stack)
  - [Garbage collection](#garbage-collection)
- [References](#references)

## Recap

**Attributes** define the features of an object. **Methods** define the behaviour of an object.

```java
// MyClass.java
public class MyClass {
  // This is accessible on the class instance (i.e. `new`)
  public int myProperty;

  // This property is available on the class (i.e. no New)
  public static int myStaticProp;

  public MyClass() {
    // this is the contructor for this class
  }

  public void myMethod(String myParameter) {
    // This is a method that is part of the instance
  }

  public static void myStaticMethod() {
    // This method is accessible without calling `new`
  }
}

// Main.java
public class MainProgram {
  // Main function
  public static void main(String[] args) {
    // Constructor in myClass is called
    MyClass myClass = new MyClass();
    // Using the static method
    MyClass.myStaticMethod();
    // Using the instance method
    myClass.myMethod();
  }
}
```

## The Heap and the Stack

When `new` is called, then a **reference** to the object is created.

```java
...
  // `myClass` is a reference to the object on the heap
  MyClass myClass = new MyClass();
  // `refMyClass` is a reference to the same object as myClass
  MyClass refMyClass = myClass;
  // Warning! references can be lost...
  myClass = null;
  // ... and therefore can cause bugs/faults
  myClass.myMethod() // ERROR!
...
```

Compare `java` with the following `c` program:

```c
public void main() {
  int arr[1000000]; // ERROR!
  int *arr = (int *)malloc(sizeof(int) * 1000000); // Fine
}
```

The reason why the first line fails is because the memory requested exceeds the size of the stack. However, the second line would work because the memory is allocated on the heap, which has access to the entire computer's memory.

### Garbage collection

When a reference to an object is lost, the built-in memory garbage collector in `java` frees memory on the heap which allows it to be used again, unlike in `c`. This also occurs **at the end of the `main` program.**

## References

###
