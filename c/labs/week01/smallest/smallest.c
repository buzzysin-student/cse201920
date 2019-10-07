#include <stdio.h>

int smallestInt(int high, long low)
{
  // Find the middle of the interval
  long mid = low + (high - low) / 2;
  int test = mid;

  if (test == mid)
  {
    high = mid;
  }
  else
  {
    low = mid;
  }

  printf("High: %d, Low: %d, Mid: %d, Test: %d\n", high, low, mid, test);

  if (high - low <= 2) // Because I know that -2^31 is even
    return test;
  else
    return smallestInt(high, low);
}

int main(void)
{
  printf("The smallest int is %d\n", smallestInt(0, -2500000000));
  return 0;
}
