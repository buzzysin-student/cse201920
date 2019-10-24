/* Classify a triangle according to the integer lengths of its sides. */

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  unsigned long sideMax = getExtreme(TRI_SIDES, sides, 1);
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

  // a ^ 2 + b ^ 2 == c ^ 2 ? yup : nope
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

// Integer constants representing types of triangle.
enum
{
  Equilateral,
  Isosceles,
  Right,
  Scalene,
  Flat,
  Impossible,
  Illegal
};

// Convert a string into an integer.  Return -1 if it is not valid.
int convert(const char length[])
{
  int n = strlen(length);
  int pow = 0;
  unsigned int result = 0;

  if (n > 0 && length[0] == CHR_MAX)
    return -1;

  while (n)
  {
    int ascii = (int)length[n - 1] - CHR_MAX;
    result += ascii * getPower(10, pow); // i * (10 ^ pow)

    if (ascii < NUM_MIN || ascii > NUM_MAX)
      return -1;

    pow++;
    n--;
  }

  if (result > INT_MAX)
    return -1;

  return result;
}

// Classify a triangle, given side lengths as strings:
int triangle(int a, int b, int c)
{
  int validity = triValidity(a, b, c);

  if (validity == 0)
    return Impossible;
  if (validity == 1)
    return Flat;
  if (validity == 2)
  {
    if (triIsRight(a, b, c))
      return Right;
    if (triMustEqualSides(a, b, c))
      return Equilateral;
    if (triHasEqualSides(a, b, c))
      return Isosceles;
    else
      return Scalene;
  }
  else
    return -1;
}

// -----------------------------------------------------------------------------
// User interface and testing.

void print(int type)
{
  switch (type)
  {
  case Equilateral:
    printf("Equilateral");
    break;
  case Isosceles:
    printf("Isosceles");
    break;
  case Right:
    printf("Right");
    break;
  case Scalene:
    printf("Scalene");
    break;
  case Flat:
    printf("Flat");
    break;
  case Impossible:
    printf("Impossible");
    break;
  case Illegal:
    printf("Illegal");
    break;
  }
  printf("\n");
}

// A replacement for the library assert function.
void assert(int line, bool b)
{
  if (b)
    return;

  printf("The test on line %d fails.\n", line);
  exit(1);
}

// Check that you haven't changed the triangle type constants.  (If you do, it
// spoils automatic marking, when your program is linked with a test program.)
void checkConstants()
{
  assert(__LINE__, Equilateral == 0 && Isosceles == 1 && Right == 2 && Scalene == 3);
  assert(__LINE__, Flat == 4 && Impossible == 5 && Illegal == 6);
}

// Tests 1 to 2: check equilateral
void testEquilateral()
{
  assert(__LINE__, triangle(8, 8, 8) == Equilateral);
  assert(__LINE__, triangle(1073, 1073, 1073) == Equilateral);
}

// Tests 3 to 5: check isosceles
void testIsosceles()
{
  assert(__LINE__, triangle(25, 25, 27) == Isosceles);
  assert(__LINE__, triangle(25, 27, 25) == Isosceles);
  assert(__LINE__, triangle(27, 25, 25) == Isosceles);
}

// Tests 6 to 14: check right angled
void testRight()
{
  assert(__LINE__, triangle(3, 4, 5) == Right);
  assert(__LINE__, triangle(3, 5, 4) == Right);
  assert(__LINE__, triangle(5, 3, 4) == Right);
  assert(__LINE__, triangle(5, 12, 13) == Right);
  assert(__LINE__, triangle(5, 13, 12) == Right);
  assert(__LINE__, triangle(12, 5, 13) == Right);
  assert(__LINE__, triangle(12, 13, 5) == Right);
  assert(__LINE__, triangle(13, 5, 12) == Right);
  assert(__LINE__, triangle(13, 12, 5) == Right);
}

// Tests 15 to 20: check scalene
void testScalene()
{
  assert(__LINE__, triangle(12, 14, 15) == Scalene);
  assert(__LINE__, triangle(12, 15, 14) == Scalene);
  assert(__LINE__, triangle(14, 12, 15) == Scalene);
  assert(__LINE__, triangle(14, 15, 12) == Scalene);
  assert(__LINE__, triangle(15, 12, 14) == Scalene);
  assert(__LINE__, triangle(15, 14, 12) == Scalene);
}

// Tests 21 to 25: check flat
void testFlat()
{
  assert(__LINE__, triangle(7, 9, 16) == Flat);
  assert(__LINE__, triangle(7, 16, 9) == Flat);
  assert(__LINE__, triangle(9, 16, 7) == Flat);
  assert(__LINE__, triangle(16, 7, 9) == Flat);
  assert(__LINE__, triangle(16, 9, 7) == Flat);
}

// Tests 26 to 31: check impossible
void testImpossible()
{
  assert(__LINE__, triangle(2, 3, 13) == Impossible);
  assert(__LINE__, triangle(2, 13, 3) == Impossible);
  assert(__LINE__, triangle(3, 2, 13) == Impossible);
  assert(__LINE__, triangle(3, 13, 2) == Impossible);
  assert(__LINE__, triangle(13, 2, 3) == Impossible);
  assert(__LINE__, triangle(13, 3, 2) == Impossible);
}

// Tests 32 to 44: check conversion.
// Leading zeros are disallowed because thy might be mistaken for octal.
void testConvert()
{
  assert(__LINE__, convert("1") == 1);
  assert(__LINE__, convert("12345678") == 12345678);
  assert(__LINE__, convert("2147483647") == 2147483647);
  assert(__LINE__, convert("2147483648") == -1);
  assert(__LINE__, convert("2147483649") == -1);
  assert(__LINE__, convert("0") == -1);
  assert(__LINE__, convert("-1") == -1);
  assert(__LINE__, convert("-2") == -1);
  assert(__LINE__, convert("-2147483648") == -1);
  assert(__LINE__, convert("x") == -1);
  assert(__LINE__, convert("4y") == -1);
  assert(__LINE__, convert("13.4") == -1);
  assert(__LINE__, convert("03") == -1);
}

// Tests 45 to 50: check for correct handling of overflow
void testOverflow()
{
  assert(__LINE__, triangle(2147483647, 2147483647, 2147483646) == Isosceles);
  assert(__LINE__, triangle(2147483645, 2147483646, 2147483647) == Scalene);
  assert(__LINE__, triangle(2147483647, 2147483647, 2147483647) == Equilateral);
  assert(__LINE__, triangle(1100000000, 1705032704, 1805032704) == Scalene);
  assert(__LINE__, triangle(2000000001, 2000000002, 2000000003) == Scalene);
  assert(__LINE__, triangle(150000002, 666666671, 683333338) == Scalene);
}

// Run tests on the triangle function.
void test()
{
  checkConstants();
  testEquilateral();
  testIsosceles();
  testRight();
  testScalene();
  testFlat();
  testImpossible();
  testConvert();
  testOverflow();
  printf("All tests passed\n");
}

// Run the program or, if there are no arguments, test it.
int main(int n, char *args[n])
{
  setbuf(stdout, NULL);
  if (n == 1)
  {
    test();
  }
  else if (n == 4)
  {
    int a = convert(args[1]), b = convert(args[2]), c = convert(args[3]);
    int result = triangle(a, b, c);
    print(result);
  }
  else
  {
    fprintf(stderr, "Use e.g.: ./triangle 3 4 5\n");
    exit(1);
  }
  return 0;
}
