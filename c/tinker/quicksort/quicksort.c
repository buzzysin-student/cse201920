#include <stdio.h>
#include <stdlib.h>

void createArr(int *dest, int size)
{
  dest = malloc(size);
}

void deleteArr(int *dest)
{
  free(dest);
}

int main(int argc, char **argv)
{
  printf("Args: %d\n", argc);

  int *arr = NULL;

  createArr(arr, sizeof(int) * 8);
  deleteArr(arr);

  return 0;
}
