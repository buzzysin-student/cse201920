#include "../resources/lab-2_q.h"

char *printBin(int8_t x)
{
  char bin[9];
  bin[8] = '\0';

  for (int i = 7; i >= 0; i--)
  {
    printf("%d", (x >> i) & 1);
    bin[i] = (char)(((x >> i) & 1) + 48);
  }

  printf("\n");

  return bin;
}

int8_t sign(int8_t x)
{
  return (x >> 7) && 1;
}

int8_t signum(int8_t x)
{
  // NeGative flag
  int8_t ng = (x >> 7) & 1;
  // ZeRo flag
  int8_t zr = (x ^ 255) == 255;

  printBin(x);
  printBin(ng);
  printBin(zr);

  if (!ng)
    if (zr)
      return 0;
    else
      return 1;
  else
    return -1;
}

int8_t neg(int8_t x)
{
  return (x ^ (int8_t)255) + (int8_t)1;
}

int8_t mod(uint8_t x, int n)
{
  int8_t y;
}

// Ex2Ca
void ex2Ca()
{
  int8_t test;

  printf("What type of number is: ");
  scanf("%hhd", &test);
  printf("\n");

  printf("%d is a %s number\n", test, sign(test) ? "negative" : "positive");
}

// Ex2Cb
void ex2Cb()
{
  int8_t test;

  printf("Number to negate: ");
  scanf("%hhd", &test);

  printBin(test);
  printBin(neg(test));
}

// Ex2Ce
void ex2Ce()
{
  int8_t test;

  printf("What type of number is: ");
  scanf("%hhi", &test);
  printf("\n");

  printf("sgn(%d) = %d\n", test, signum(test));
}

int main(void)
{

  ex2Ca();
  ex2Cb();
  ex2Ce();

  for (int i = 0; i < 80; i += 8)
  {
    printBin(i);
  }

  return 0;
}
