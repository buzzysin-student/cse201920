#include <stdio.h>

int calls;

int f(int y) {
  int total;
  if (y <= 0)
    total = 1;
  else
    total = y * f(y - 1);
  calls += 1;
  return total;
}

int main(void) {
  calls = 0;
  int n = f(4);
  printf("Total is %d after %d calls\n", n, calls);
}
