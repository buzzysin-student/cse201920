// * see ./structs.h
#include "structs.h"

#include <stdio.h>

int main(int n, char *args[])
{
  // ? Using a structure
  item itemData = {137, 91};
  item *i = &itemData;

  // ? Access subvariables using dot notation (i.e. struct.variable)
  // Old implementation
  // i.x++;
  // i.y = i.y += 15;

  // New implemenation
  move(i, 1, 15);

  printf("%d, %d\n", i->x, i->y);

  return 0;
}
