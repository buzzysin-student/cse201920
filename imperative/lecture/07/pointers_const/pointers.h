// POINTER ANALYSIS

void pointers()
{
  char s[] = "Brexit"; // * array initialialised with a string constant
  char *t = "Brexit";  // * pointer to a string constant in memory

  // ! NOTE THAT t[1] = r as pointer notation is _syntactic sugar_ for array notation
  // ! Also, t points to IMMUTABLE characters (?check this) in memory

  t = s;      // * Make t point to non-constant string
  t[1] = 'r'; // * This is legal as s contains mutable characters

  int i = 3, *p = &i, **q = &p;
  // * i is an integer
  // * p is a pointer to value i
  // * q is a pointer to a pointer to i
  // ? This is called indirection - of which here, there are 3 levels

  int *w[] = {p, &i, *q}; // Array of pointers to integer i, all equivalent notation
}
