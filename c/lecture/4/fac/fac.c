#include <stdio.h>

int fac(int n)
{
  if (n == 1)
    return 1;
  else
    return n * fac(n - 1);
}

int fib(int n)
{
  if (n == 1)
    return 1;
  else if (n == 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main(int n, char *argv[])
{
  int toFac;

  if (n > 1)
  {
    toFac = atoi(argv[1]);
    printf("%d! = %d\n", toFac, fac(toFac));
  }
  else
  {
    printf("No args.");
  }
  return 0;
}
