#include <stdio.h>

double square(double n)
{
  return n * n;
}

int main()
{
  double squaredNum = square(25);
  printf("25 squared is %f\n", squaredNum);
}