/* Fund the square root */
#include <stdio.h>
#include <math.h>

// Square root using Newton Algorithm
double root(double x)
{
  double r = x / 2.0; // Initial guess
  double epsilon = 1E-15;
  while (fabs(r - x / r) / 2.0 > epsilon)
  {
    r = (r + x / r) / 2.0; // Newton step
  }
  return r;
}

int main(void)
{
  double num;
  printf("Enter your number: ");
  scanf("%lf", &num);
  printf("%lf", root(num));
  printf("\n");
  return 0;
}
