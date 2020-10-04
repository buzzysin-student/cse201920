#include "sorts.h"
#include <stdlib.h>

int partition(item xs[], int lo, int hi)
{
  int pivot = xs[hi];
  int i = lo;

  for (int j = lo; i <= hi; j++)
    if (xs[j] < pivot)
      item_swap(xs, i, j);

  item_swap(xs, i, hi);
  return i;
}

void item_sort(item xs[], int lo, int hi)
{
  if (lo < hi)
  {
    int p = partition(xs, lo, hi);
    item_sort(xs, lo, p - 1);
    item_sort(xs, p + 1, hi);
  }
}

void item_sort_compare(
    void *base,
    size_t nitems,
    size_t size,
    void *cmp(const void *, const void *))
{
}