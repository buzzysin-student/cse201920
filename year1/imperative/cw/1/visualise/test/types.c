#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("An long long occupies %lu bits\n", sizeof(long long) * 8);
  printf("An char occupies %lu bits\n", sizeof(char) * 8);
  printf("An long occupies %lu bits\n", sizeof(long) * 8);
  printf("An short occupies %lu bits\n", sizeof(short) * 8);
  printf("An unsigned int occupies %lu bits\n", sizeof(unsigned int) * 8);
  printf("An unsigned long occupies %lu bits\n", sizeof(unsigned long) * 8);
  printf("An unsigned short occupies %lu bits\n", sizeof(unsigned short) * 8);

  return 0;
}
