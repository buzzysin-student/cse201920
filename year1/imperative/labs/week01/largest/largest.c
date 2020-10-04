#include <stdio.h>

int largestInt(int low, long high)
{
  // Find the middle of the interval [low, high]
  long mid = low + (high - low) / 2;
  // Test value = Integer middle value (convert mid to int [rounding])
  int test = mid;

  // If the integer value is the same as the
  // center of the interval
  if (test == mid)
  {
    // Increase the lower boundary
    low = mid;
  }
  else
  {
    // Decrease the upper boundary
    high = mid;
  }

  // If the interval consists only of the boundaries
  // then return the integer at the "center" of the
  // interval
  if (high - low < 2)
    return test;
  // Otherwise, continue to reduce the boundaries
  // by recursively running this function.
  else
    return largestInt(low, high);
}

int main()
{
  int n = largestInt(0, 2500000000);
  printf("The largest int is %d\n", n);
  return 0;
}