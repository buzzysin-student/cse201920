#include <stdio.h>

int sum(int n)
{
  printf("The address of argument n=%d is %p\n", n, &n);
  if (n == 1)
    return n;
  else
    return n + sum(n - 1);
}

int main()
{
  printf("%d\n", sum(100)); // Overuse of the stack can cause a stack-overflow
  return 0;
}
