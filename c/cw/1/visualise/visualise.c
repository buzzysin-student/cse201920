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
  USHT = sizeof(unsigned short),
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

void assert(int ln, int expr)
{
  if (expr)
    return;
  else
  {
    printf("Line %d fails\n", ln);
    exit(1);
  }
}

void printBase(int n, long amount, int sign, int bits, char out[])
{
  int max_pwr = ceil(bits / log2(n));
  int sf = n < 4 ? 3 : 0;

  int cnt = 0;
  for (int i = max_pwr - 1; i >= 0; i--)
  {
    int count = 0;
    unsigned long placeValue = pwr(n, i);

    if (amount > 0)
      while (placeValue <= amount)
      {
        amount -= placeValue;
        count++;
      }
    else
      while (amount < 0)
      {
        amount += placeValue;
        count++;
      }

    char *space = (i) % (int)(log2(n) + sf) == 0 ? " " : "";

    printf("%c%s", int2HexChar(count), space);
    out[cnt++] = int2HexChar(count);
  }

  out[cnt] = 0;
  printf("\n");
}

void adjustMetadata(char type[], int *bitPtr, long long *minPtr, long long *maxPtr, int sgn)
{

  if (strcmp(type, "int") == 0)
  {
    *bitPtr = SINT * 8;
    if (sgn == 0)
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
    if (sgn == 0)
    {
      *maxPtr = UCHAR_MAX;
    }
    else
    {
      *minPtr = CHAR_MIN;
      *maxPtr = CHAR_MAX;
    }
  }

  else if (strcmp(type, "long") == 0)
  {
    *bitPtr = LONG * 8;
    if (sgn == 0)
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
    if (sgn == 0)
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

void summarise(char type[], long long amount, int sgn, char *test, int ln)
{
  int bits = -1;
  long long min = 0;
  long long max = 0;
  char result[1000];

  adjustMetadata(type, &bits, &min, &max, sgn);

  if (bits == -1)
  {
    printf("Unable to show type %s%s at current.\n\n", sgn ? "" : "unsigned ", type);
    return;
  }

  char sgnbit = (amount >> (bits - 1)) & 1;

  printf("------------------\n");
  if (sgn)
  {
    printf("%s %lli => signed %d bits => [%lli, %lli]\n", type, amount, bits, min, max);
    printf("significant bit => %d (%s)\n", sgnbit, sgnbit ? "negative" : "positive");
  }
  else
  {
    printf("%s %llu => unsigned %d bits => [%llu, %llu]\n", type, amount, bits, min, max);
  }
  printf("------------------\n");

  if ((amount > max || amount < min))
  {
    strcpy(result, "OVERFLOW");
    printf("%s\n", result);
  }
  else
  {
    printf("\nBinary\n======\n");
    printBase(2, amount, sgn, bits, result);

    if (strlen(test))
    {
      assert(ln, strcmp(test, result) == 0);
    }

    printf("\nOctal\n=====\n");
    printBase(8, amount, sgn, bits, result);

    printf("\nHexadecimal\n===========\n");
    printBase(16, amount, sgn, bits, result);

    if (amount <= CHAR_MAX && amount >= CHAR_MIN)
      printf("\nCharacter\n=========\n\'%c\'\n", (char)amount);
  }

  printf("\n");
}

void test()
{
  // * Extreme Signed Char
  summarise("char", CHAR_MAX, 1, "01111111", __LINE__);
  summarise("char", CHAR_MAX + 1, 1, "OVERFLOW", __LINE__);
  summarise("char", CHAR_MIN, 1, "10000000", __LINE__);
  summarise("char", CHAR_MIN - 1, 1, "OVERFLOW", __LINE__);

  // * Extreme Signed Int
  summarise("int", INT_MAX, 1ULL, "01111111111111111111111111111111", __LINE__);
  summarise("int", INT_MAX + 1ULL, 1, "OVERFLOW", __LINE__);
  summarise("int", INT_MIN, 1ULL, "10000000000000000000000000000000", __LINE__);
  summarise("int", INT_MIN - 1ULL, 1, "OVERFLOW", __LINE__);

  // * Extreme Signed Long
  summarise("long", LONG_MAX, 1ULL, "0111111111111111111111111111111111111111111111111111111111111111", __LINE__);
  summarise("long", LONG_MAX + 1ULL, 0, "OVERFLOW", __LINE__);
  summarise("long", LONG_MIN, 1ULL, "1000000000000000000000000000000000000000000000000000000000000000", __LINE__);
  // ! Warning - false positive - this result should overflow.
  summarise("long", LONG_MIN - 1ULL, 1, "0111111111111111111111111111111111111111111111111111111111111111", __LINE__);
  // ! End warning

  // * Extreme Signed Short
  summarise("short", SHRT_MAX, 1, "0111111111111111", __LINE__);
  summarise("short", SHRT_MAX + 1ULL, 1, "OVERFLOW", __LINE__);
  summarise("short", SHRT_MIN, 1ULL, "1000000000000000", __LINE__);
  summarise("short", SHRT_MIN - 1ULL, 1, "OVERFLOW", __LINE__);

  // * Extreme Unsigned Char
  summarise("char", UCHAR_MAX, 0, "11111111", __LINE__);
  summarise("char", UCHAR_MAX + 1, 0, "OVERFLOW", __LINE__);
  summarise("char", 0, 0, "00000000", __LINE__);
  summarise("char", -1ULL, 0, "OVERFLOW", __LINE__);
  
  // * Extreme Unsigned Int
  summarise("int", UINT_MAX, 0, "11111111111111111111111111111111", __LINE__);
  summarise("int", UINT_MAX + 1ULL, 0, "OVERFLOW", __LINE__);
  summarise("int", 0, 0, "00000000000000000000000000000000", __LINE__);
  summarise("int", -1ULL, 0, "OVERFLOW", __LINE__);

  // * Extreme Unsigned Long
  // ! Warning - The use of 'long long' to contain smaller types has backfired here.
  // ! All of these results are false positives.
  summarise("long", ULONG_MAX, 0, "OVERFLOW", __LINE__);
  summarise("long", ULONG_MAX + 1ULL, 0, "OVERFLOW", __LINE__);
  summarise("long", 0, 0, "OVERFLOW", __LINE__);
  summarise("long", -1ULL, 0, "OVERFLOW", __LINE__);
  // ! End Warning

  // * Extreme Unsigned Short
  summarise("short", USHRT_MAX, 0, "1111111111111111", __LINE__);
  summarise("short", USHRT_MAX + 1ULL, 0, "OVERFLOW", __LINE__);
  summarise("short", 0, 0, "0000000000000000", __LINE__);
  summarise("short", -1ULL, 0, "OVERFLOW", __LINE__);

  printf("All tests pass\n");
}

int main(int argc, char *argv[])
{
  char *type;
  long amount;

  if (argc != 3 && argc != 4)
  {
    test();
    // printf("%lli\n", (__int128)LONG_MIN - 1ull);
  }
  else
  {
    if (argc == 3)
    {
      type = argv[1];
      amount = atol(argv[2]);
      summarise(type, amount, 1, "", 0);
    }
    else if (argc == 4)
    {
      type = argv[2];
      amount = atol(argv[3]);
      summarise(type, amount, 0, "", 0);
    }
  }

  return 0;
}
