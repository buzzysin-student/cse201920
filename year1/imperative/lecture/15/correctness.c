#include <stdio.h>

// ! NOTE THAT THE HOEARE TRIPLES DO NOT HALT
// ! EXECUTION!

int main(void) {
  // * Hoare Triples
  // ? if pre-condition is true, then execute statement,
  // ? then check post-condition
  int x = 12;
  int y = 3;

  { x == 12; }
  x++;
  { x == 13; }
  printf("Line ./correctness.c:%d : X = %d, Y = %d\n", __LINE__, x, y);

  { x == 13 && y == 3; }
  y += x;
  { y == 16; }
  printf("Line ./correctness.c:%d : X = %d, Y = %d\n", __LINE__, x, y);

  // * Sequencing rule
  // ? Similar to discrete maths "modus ponens" and other
  // ? inference rules
  // ? if { P } S1 { Q }, { Q } S2 { R } then { P } S1; S2; { Q }
  // * Or in logic terms:
  // ? ((p -> q).(q -> r)) -> (p -> r)

  // ? Task: try to find an intermediate statement such that
  // ? the statments can be split
  { 1; }
  x = 1;
  y = 2;
  printf("Set x to %d, y to %d\n", 1, 2);
  { x == 1 && y == 2; }
  printf("Line ./correctness.c:%d : X = %d, Y = %d\n", __LINE__, x, y);

  // * Result:
  { 1; }
  x = 1;
  printf("Set x to %d\n", 1);
  { x == 1; }
  { x == 1; }
  y = 2;
  printf("Set y to %d\n", 2);
  { x == 1 && y == 2; }
  printf("Line ./correctness.c:%d : X = %d, Y = %d\n", __LINE__, x, y);

  // * Abstracting the if statment
  // ? Normal if:
  if (x == 1)
    y = 2;
  else
    y = 3;
  printf("Line ./correctness.c:%d : X = %d, Y = %d\n", __LINE__, x, y);

  // ? Abstracted if
  { 1 && x == 1; }
  y = 2;
  printf("Set y to %d\n", 2);
  { y == 2; }
  printf("Line ./correctness.c:%d : X = %d, Y = %d\n", __LINE__, x, y);
  // ? Abstracted else
  { 1 && x != 1; }
  y = 3;
  printf("Set y to %d\n", 3);
  { y == 3; }
  printf("Line ./correctness.c:%d : X = %d, Y = %d\n", __LINE__, x, y);

  // TODO: HOARE WHILE EXECUTION LOAGIC
}