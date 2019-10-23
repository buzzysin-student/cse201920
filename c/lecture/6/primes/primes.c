/**
 * ? Task - find primes
 */

#include <stdio.h>

int isPrime(int n)
{
  if (n < 1)
    return 0;
  else if (n == 2)
    return 1;
  else
    for (int i = 2; i < n; i++)
      if (n % i == 0)
        return 0;

  return 1;
}

void linearPrimes()
{
  int n = 0, cnt = 2;

  printf("How many primes do you want? ->");
  scanf("%d", &n);

  while (n)
  {
    if (isPrime(cnt))
    {
      printf("%d ", cnt);
      n--;
    }

    cnt++;
  }

  printf("\n");
}

int eratosthenes()
{
  int n = 0, cnt = 2;

  printf("How many primes do you want? ->");
  scanf("%d", &n);

  
}

int main(int argc, char *argv[])
{
  linearPrimes();
  eratosthenes();
  return 0;
}