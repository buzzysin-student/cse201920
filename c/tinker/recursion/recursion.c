#include <stdio.h>

int sumEvenNumbersUntil (int x) 
{
  if(x == 0) {
    return x;
  }

  if(x % 2 == 0 && x > 0) {
    return x + sumEvenNumbersUntil(x - 2);
  }

  else {
    return x + sumEvenNumbersUntil(x - 1);
  }
}

int main(void) {
  int numToSum;

  scanf("Num to sum: %d\n", numToSum);
  printf("Summed num: %d\n", sumEvenNumbersUntil(numToSum));

  return 0;
}