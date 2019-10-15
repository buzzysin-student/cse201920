#include <stdio.h>

int fib(int n)
{
  if (n > 0 && n < 2)
    return 0;
  else if (n == 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main(int n, char *argv[])
{
  int toFib;

  if (n > 1)
  {
    toFib = atoi(argv[1]);
    printf("F_%d = %d\n", toFib, fib(toFib));
  }
  else
  {
    printf("No args.");
  }
  return 0;
}
