#include <stdio.h>

int main(void)
{
  int seq[3]; /* sequence of 3 integers - all elements are empty */
  // The size of seq will stay at 3 elements
  seq[1] = 2; // [NULL, 2, NULL]
  seq[0] = 4; // [4, 2, NULL]

  /* A shorter way: */
  int shortSeq[3] = {3, 5, 7};
}