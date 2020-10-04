#include "sorts.h"

void item_sort(int n, item xs[n])
{
  for (int m = n - 1; m > 0; m--)
    for (int i = 0; i < m; i++)
      if (xs[i] > xs[m])
        item_swap(i, m, xs);

  return;
}
