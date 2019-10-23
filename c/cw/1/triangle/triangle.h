// Added library
#include <math.h>

int getExtreme(int n, int sides[], int extreme)
{
  unsigned int max = 0;
  unsigned int min = INT_MAX;

  while (n)
  {
    if (extreme == 1)
    {
      if (max < sides[n - 1])
        max = sides[n - 1];
    }

    else
    {
      if (min > sides[n - 1])
        min = sides[n - 1];
    }
    n--;
  }

  return extreme ? max : min;
}

int triValidity(int a, int b, int c)
{
  unsigned int sides[3] = {a, b, c};
  // E.g. a
  unsigned int sideMax = getExtreme(3, sides, 1);
  // E.g. a + b + c
  unsigned int sideSum = a + b + c;
  // e.g b + c
  unsigned int sideSumElse = sideSum - sideMax;
  // if b + c > a

  printf("%ld >= %d ? %d\n", sideSumElse, sideMax, sideSumElse >= sideMax);

  if (sideSumElse > sideMax)
  {
    printf("%d %d %d is fine\n", a, b, c);
    return 2;
  }

  else if (sideSumElse == sideMax)
  {
    printf("%d %d %d is flat\n", a, b, c);
    return 1;
  }

  else
  {
    printf("%d %d %d is impossible\n", a, b, c);
    return 0;
  }
}

int triHasEqualSides(int a, int b, int c)
{
  if (a == b || b == c || a == c)
    return 1;

  return 0;
}

int triMustEqualSides(int a, int b, int c)
{
  if (a == b && b == c)
    return 1;

  return 0;
}

int triIsRight(int a, int b, int c)
{
  int sides[3] = {a, b, c};
  int minSide = getExtreme(3, sides, 0);
  int maxSide = getExtreme(3, sides, 1);
  int sideSum = a + b + c;
  int midSide = sideSum - minSide - maxSide;

  double nMin = minSide / maxSide;
  double nMid = midSide / maxSide;
  double nHyp = (nMin * nMin) + (nMid * nMid);
  int roundedHyp = (int)nHyp;

  if (nHyp - (double)roundedHyp > 0)
    return 0;

  printf("min = %d, mid = %d, max = %d\n", minSide, midSide, maxSide);

  // E.g a / c
  double oppHyp = ((double)minSide / (double)maxSide);
  // E.g. b / c
  double adjHyp = ((double)midSide / (double)maxSide);

  double oppRad = asin(oppHyp);
  double adjRad = asin(adjHyp);
  double hypRad = asin(1); // * pi / 2

  double epsilon = 1e-06;

  printf("Rads: %hhf %hhf %hhf (countersum: %hhf)\n", oppRad, adjRad, hypRad, oppRad + adjRad);

  if (oppRad + adjRad - hypRad < epsilon)
    return 1;

  return 0;
}

int getPower(int n, int pow)
{
  if (pow == 0)
    return 1;
  else
    return n * getPower(n, pow - 1);
}