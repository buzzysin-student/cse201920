#include <stdlib.h>

int main(void)
{
  /*
   * Every variable has a memory location that holds its 
   * value, somewhere in the memory
   * 
   ? A pointer is a reference to the memory location
   */
  void *ptr;

  /*
   ? How does a c program structure memory
   *
   * Each byte has a unique byte-based index (called the 
   * address of the byte [byte = 8 bits])
   * 
   * Address space is assigned to the program (?at runtime)
   */

  /* 
   * Example 4-byte integers...
   * _____________
   * |   |   |   |
   * 0---4---8---...
   * 
   * Each type has a particular size, so every element will
   * take 4 bytes in this case, but will not be indexed as 
   * 0,4,8,... but still as 0,1,2,...
   */

  /*
   * In c, pointers hold a reference to an address and are
   * variables, and so also have an address themselves
   */

  /*
   * Example:
   */
  int i, j, k = 137;
  int a[3] = {2, 4, 6};
  
  // ? Pointer to an int variable
  int *p; // ! Pointer to nowhere (? random location)!

  // ? the `&` in &var returns the ADDRESS of the value, not the value itself
  p = &k; // ? Now points to the integer at the address of `k`

  // ! Additionally, the pointer refers to the first byte at `k`

  return 0;
}