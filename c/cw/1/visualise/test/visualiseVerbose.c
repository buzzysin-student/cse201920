#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Types
{
  SINT = sizeof(signed int),
  CHAR = sizeof(char),
  LONG = sizeof(signed long),
  SHRT = sizeof(signed short),
  FLOT = sizeof(float),
  DBLE = sizeof(double),
  UINT = sizeof(unsigned int),
  ULNG = sizeof(unsigned long),
  USHT = sizeof(unsigned short)
};

unsigned long pwr(int n, int p)
{
  if (p == 0)
    return 1;
  else
    return n * pwr(n, p - 1);
}

char int2HexChar(int n)
{
  switch (n)
  {
  case 10:
    return 'A';
  case 11:
    return 'B';
  case 12:
    return 'C';
  case 13:
    return 'D';
  case 14:
    return 'E';
  case 15:
    return 'F';
  default:
    return (char)(48 + n);
  }
}

void printBase(int n, long amount, int bits, int sgn)
{
  int max_pwr = ceil(bits / log2(n));
  int sf = n < 4 ? 3 : 0;

  // printf("mp = %d, pv = %li\n", max_pwr, pwr(n, max_pwr));

  for (int i = max_pwr - 1; i >= 0; i--)
  {
    int count = 0;
    unsigned long placeValue = pwr(n, i);

    // printf("%d\n", amount);

    // printf("i = %d, i == mp = %d\n", i, i == max_pwr - 1);

    if (amount > 0)
    {
      // printf("Amount > 0\n");
      while (placeValue <= amount)
      {
        // printf("%li - %d^%d\n", amount, n, i);
        amount -= placeValue;
        count++;
      }
    }
    else
    {
      // printf("Amount <= 0\n");
      while (amount < 0)
      {
        // printf("%li + %d^%d\n", amount, n, i);
        amount += placeValue;
        count++;
      }
    }

    printf("%c%s", int2HexChar(count), (i) % (int)(log2(n) + sf) == 0 ? " " : "");
  }

  printf("\n");
}

void adjustMetadata(char type[], int *bitPtr, long *minPtr, long *maxPtr, int sgn)
{

  if (strcmp(type, "int") == 0)
  {
    *bitPtr = SINT * 8;
    if (sgn)
    {
      *maxPtr = UINT_MAX;
    }
    else
    {
      *minPtr = INT_MIN;
      *maxPtr = INT_MAX;
    }
  }

  else if (strcmp(type, "char") == 0)
  {
    *bitPtr = CHAR * 8;
    *minPtr = CHAR_MIN;
    *maxPtr = CHAR_MAX;
  }

  else if (strcmp(type, "long") == 0)
  {
    *bitPtr = LONG * 8;
    if (sgn)
    {
      *maxPtr = ULONG_MAX;
    }
    else
    {
      *minPtr = LONG_MIN;
      *maxPtr = LONG_MAX;
    }
  }

  else if (strcmp(type, "short") == 0)
  {
    *bitPtr = SHRT * 8;
    if (sgn)
    {
      *maxPtr = USHRT_MAX;
    }
    else
    {
      *minPtr = SHRT_MIN;
      *maxPtr = SHRT_MAX;
    }
  }
}

void summarise(char type[], long amount, int sgn)
{
  int bits = -1;
  long min = 0;
  long max = 0;

  adjustMetadata(type, &bits, &min, &max, sgn);

  if (bits == -1)
  {
    printf("Unable to show type %s at current.\n", type);
    return;
  }

  char sgnbit = (amount >> (bits - 1)) & 1;

  printf("%s %li - %s %d bits - => [%li, %li]\n", type, amount, sgn ? "signed" : "unsigned", bits, min, max);

  if (sgn)
    printf("significant bit -> %d (%s)\n", sgnbit, sgnbit ? "negative" : "positive");

  printf("\nBinary\n======\n");
  printBase(2, amount, bits, sgn);

  printf("\nOctal\n=====\n");
  printBase(8, amount, bits, sgn);

  printf("\nHexadecimal\n===========\n");
  printBase(16, amount, bits, sgn);

  if (amount <= 127 && amount >= -128)
    printf("\nCharacter\n=========\n%c\n", (char)amount);

  printf("\n");
}

void test()
{
  // * Extreme Signed Char
  summarise("char", CHAR_MAX - 1, 1);
  summarise("char", CHAR_MAX, 1);
  summarise("char", CHAR_MIN, 1);
  summarise("char", CHAR_MIN + 1, 1);
  // * Extreme Signed Int
  summarise("int", INT_MAX - 1, 1);
  summarise("int", INT_MAX, 1);
  summarise("int", INT_MIN, 1);
  summarise("int", INT_MIN + 1, 1);
  // * Extreme Signed Long
  summarise("long", LONG_MAX - 1, 1);
  summarise("long", LONG_MAX, 1);
  summarise("long", LONG_MIN, 1);
  summarise("long", LONG_MIN + 1, 1);
  // * Extreme Signed Short
  summarise("short", SHRT_MAX - 1, 1);
  summarise("short", SHRT_MAX, 1);
  summarise("short", SHRT_MIN, 1);
  summarise("short", SHRT_MIN + 1, 1);
  // * Extreme Unsigned Char
  summarise("char", UCHAR_MAX - 1, 0);
  summarise("char", UCHAR_MAX, 0);
  summarise("char", 0, 0);
  summarise("char", 1, 0);
  // * Extreme Unsigned Int
  summarise("int", UINT_MAX - 1, 0);
  summarise("int", UINT_MAX, 0);
  summarise("int", 0, 0);
  summarise("int", 1, 0);
  // * Extreme Unsigned Long
  summarise("long", ULONG_MAX - 1, 0);
  summarise("long", ULONG_MAX, 0);
  summarise("long", 0, 0);
  summarise("long", 1, 0);
  // * Extreme Unsigned Short
  summarise("short", USHRT_MAX - 1, 0);
  summarise("short", USHRT_MAX, 0);
  summarise("short", 0, 0);
  summarise("short", 1, 0);
}

void usage()
{
  printf("\
=========\n\
Visualise\n\
=========\n\
\n\
---------------\n\
Supported types\n\
---------------\n\
Signed: int, char, long, short\n\
Unsigned: int, long, short\n\
\n\
-------------\n\
Example cases\n\
-------------\n\
./visualise char 48\n\
# information about the representation of (unsigned) (type) (value)\n\
# will appear down here. This includes:\n\
# * Binary representation\n\
# * Octal representation\n\
# * Hexadecimal representation\n\
# * Character representation, where applicable\n\
");
}

int main(int argc, char *argv[])
{

  char *type;
  long amount;

  if (argc != 3 && argc != 4)
  {
    test();
  }
  else
  {
    if (argc == 3)
    {
      type = argv[1];
      amount = atol(argv[2]);
      summarise(type, amount, 1);
    }
    else if (argc == 4)
    {
      type = argv[2];
      amount = atol(argv[3]);
      summarise(type, amount, 0);
    }
  }

  return 0;
}
