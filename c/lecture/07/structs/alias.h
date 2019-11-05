// ! Type aliases
// typedef struct item item; // No longer needed
// ! Adding the `const` keyword means that `word` in the program cannot change
// ! In an emergency overwrite, access is allowed with `struct word`
// typedef struct word const word; // No longer needed

// ? Note that alias names can be reused as a variable
// ? but is best avoided.

// * The size of a struct can be given by (int)sizeof(<struct>)
// * for example, sizeof(word) is 36B, much larger than the 38b
// * required
