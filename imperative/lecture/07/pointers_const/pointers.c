void func(const int *x,
          int *const y)
{
  // * const int * => says make the integer constant, pointer can be changed
  // * int * const => says make the pointer constant, value can be changed

  // ! *x = 7 doesn't word as the value that the address points to is immutable
  // ! y = x doesn't work as the address that contains the value is immutable

  // ? Doing this (creating boundaries in code) is called DEFENSIVE PROGRAMMING
  // ?
  // ? Every argument should be constant is they are not changed.
  // * I.E.
  // *
  // ? Does this pointer need to be updated ?
  // * Yes -> const int *
  // ! Not -> const * int (*) <== (optional integer constant too)
}

int main(int n, char **args)
{
  return 0;
}