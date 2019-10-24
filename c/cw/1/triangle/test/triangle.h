#include <limits.h>

enum CustomLimits
{
  TRI_SIDES = 3,
  CHR_MIN = 0,
  CHR_MAX = 48,
  NUM_MIN = 0,
  NUM_MAX = 10
};

// CW: Returns the smallest/largest side in an array of triangle sides
long getExtreme(int n, unsigned long sides[], bool extreme)
{
  long max = 0;
  long min = LONG_MAX;

  while (n)
  {
    // If we are looking for the maximum,
    // replace the max with any larger item
    // int the array.
    if (extreme == 1)
    {
      if (max < sides[n - 1])
        max = sides[n - 1];
    }

    // If we are looking for the minimum,
    // replace the max with any smaller item
    // int the array.
    else
    {
      if (min > sides[n - 1])
        min = sides[n - 1];
    }
    n--;
  }

  return extreme ? max : min;
}

// CW: Returns whether a triangle is Impossible (0) Flat (1) Or Otherwise (2)
int triValidity(int a, int b, int c)
{
  unsigned long sides[3] = {a, b, c};
  // E.g. a
  unsigned long sideMax = getExtreme(3, sides, 1);
  // E.g. a + b + c
  unsigned long sideSum = (unsigned long)a + (unsigned long)b + (unsigned long)c;
  // e.g b + c
  unsigned long sideSumElse = sideSum - sideMax;

  // printf("%ld >= %d ? %d\n", sideSumElse, sideMax, sideSumElse >= sideMax);

  // if b + c > a ==> Triangle
  if (sideSumElse > sideMax)
  {
    // printf("%d %d %d is fine\n", a, b, c);
    return 2;
  }

  // if b + c == a ==> Flat
  else if (sideSumElse == sideMax)
  {
    // printf("%d %d %d is flat\n", a, b, c);
    return 1;
  }

  // if b + c < a ==> Impossible
  else
  {
    // printf("%d %d %d is impossible\n", a, b, c);
    return 0;
  }
}

// CW: Returns whether a triangle has at least 2 equal sides
int triHasEqualSides(int a, int b, int c)
{
  return (a == b || b == c || a == c) ? 1 : 0;
}

// CW: returns whether all sides of a triangle are equal
int triMustEqualSides(int a, int b, int c)
{
  return (a == b && b == c) ? 1 : 0;
}

// CW: Returns whether a triangle has a right angle
int triIsRight(int a, int b, int c)
{
  // E.g. a ^ 2
  unsigned long a2 = (unsigned long)a * (unsigned long)a;
  // E.g. b ^ 2
  unsigned long b2 = (unsigned long)b * (unsigned long)b;
  // E.g. c ^ 2
  unsigned long c2 = (unsigned long)c * (unsigned long)c;

  // a ^ 2 + b ^ 2 == c ^ 2 ? Right : Not Right
  return (
             a2 + b2 == c2 ||
             b2 + c2 == a2 ||
             c2 + a2 == b2)
             ? 1
             : 0;
}

// CW: Helper function - returns the value of n ^ pow
long getPower(int n, int pow)
{
  if (pow == 0)
    return 1;
  else
    return n * getPower(n, pow - 1);
}
