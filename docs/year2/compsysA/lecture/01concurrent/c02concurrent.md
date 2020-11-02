# Introduction to Go <!-- omit in toc -->

[Previous Chapter][prev] | [Next Chapter][next] | [Chapter Contents][index]

[prev]: ./c01intro
[next]: ./c03prodcons
[index]: ./index

- [Reasons to use Go](#reasons-to-use-go)
- [New concepts](#new-concepts)
  - [Goroutines](#goroutines)
  - [Channels](#channels)
  - [Non-deterministic control flow](#non-deterministic-control-flow)
- [Non-Go-specific concepts](#non-go-specific-concepts)

## Reasons to use Go

- Syntactically similar to C and Java
- Semantically similar to older concurrent programming solutions

## New concepts

### Goroutines

- a thread of execution managed by the application instead of the OS

- Many goroutines can run on a single OS-thread for this reason
- It has its own call stack
- It's not _really_ a thread, but it is useful to think of it as such
- They are **multiplexed** onto threads to ensure all are running simultaneously
- They use the same address space, but this is not strictly necessary

### Channels

- Used to send messages between goroutines

  ```go
  channel := make(chan int) // UwU, int chan desu~
  sendInt := 5
  channel <- sendInt // Sending a value into a channel
  getInt := <- channel // Getting a value from a channel
  ```

### Non-deterministic control flow

- By tracing a C program, it is possible to produce the same sequence of changed memory state changes given a code segment. This is called **sequential** control flow

## Non-Go-specific concepts

- Closures - a function that returns a function as its argument

  - Allows for immutable data to be hidden (variables are mutable by default, but they are also typed!)

    ```go
    func main() {
      makeImmutableInt := func(immutable int) func() int {
        return func() int {
          return immutable
        }
      }

      thisFunctionWillAlwaysReturn2 := makeImmutableInt(2)
      giveMeA2 := thisFunctionWillAlwaysReturn2();
    }
    ```
