/* Sort an array in ascending order, using quicksort */
#include <stdio.h>
#include <stdlib.h>

// Initialise array
int *arr_new(int size)
{
  int *arr = malloc(sizeof(int) * size);
  return arr;
}

// Clear array from memory
void arr_clear(int *arr)
{
  free(arr);
}

// Print array
void arr_show(int size, int *arr, int offset)
{
  if (size > 0)
    for (int i = 0; i < size; i++)
      printf("%d ", arr[i + offset]);
  else
    printf("EMPTY");

  printf("\n");
}

// Copy array
int *arr_copy(int size, int *arr1, int *arr2, int offset)
{

  if (size > 0)
    for (int i = 0; i < size; i++)
    {
      if (offset < 0)
        arr1[i] = arr2[i - offset];
      else
        arr1[i + offset] = arr2[i];
    }

  return arr1;
}

// Sort array
int *arr_quicksort(int size, int *arr, int from, int to)
{
  if (size > 1)
  {
    // Initialise the pivot index and the pivot
    int pIndex = (int)((to + from) / 2);
    int pValue = arr[pIndex];

    // Not 100% necessary, but isolate the pivot
    // in its own single element array
    int *pAsAr = arr_new(1);
    pAsAr[0] = pValue;

    int ltCount, gtCount;
    ltCount = gtCount = 0;

    // Get the sizes of the array
    for (int i = from; i < to + 1; i++)
      if (i != pIndex)
      {
        if (arr[i] >= pValue)
          gtCount++;
        else
          ltCount++;
      }

    // Initialise the children
    int *ltArr = arr_new(ltCount);
    int *gtArr = arr_new(gtCount);

    // Initialise the child indexes (indices?)
    int gtIndex = 0, ltIndex = 0;

    for (int i = from; i < to + 1; i++)
      if (i != pIndex)
      {
        if (arr[i] >= pValue)
          gtArr[gtIndex++] = arr[i];
        else
          ltArr[ltIndex++] = arr[i];
      }

    // This ensures that the pivot is moved
    // such that is lies one index away from
    // the last index in the lower-bound list
    int nIndex = from + ltIndex;

    // SORT THE CHILDREN
    //
    // This entire process is repeated for
    // the children, copying and replacing
    // unsorted elements with sorted elements
    arr_quicksort(ltCount, ltArr, 0, ltCount - 1);
    arr_quicksort(gtCount, gtArr, 0, gtCount - 1);

    // COPY THE CHILDREN
    //
    // This replaces elements in the parent array
    // With sorted child elements
    arr_copy(ltCount, arr, ltArr, from);
    arr_copy(1, arr, pAsAr, nIndex);
    arr_copy(gtCount, arr, gtArr, nIndex + 1);

    // KILL THE CHILDREN (safely, of course)
    //
    // This must be done to avoid memory leakage
    arr_clear(ltArr);
    arr_clear(gtArr);
    arr_clear(pAsAr);
  }

  // Return
  return arr;
}

int *argstoai(int size, char *strings[])
{
  int *arr = arr_new(size);

  for (int i = 0; i < size; i++)
    arr[i] = atoi(strings[i + 1]);

  return arr;
}

int main(int n, char *argv[])
{
  if (n > 1)
  {
    int m = n - 1;
    int *arr = argstoai(m, argv);

    int *srt = arr_new(m);
    arr_copy(m, srt, arr_quicksort(m, arr, 0, m - 1), 0);

    arr_show(m, srt, 0);

    free(arr);
    free(srt);
  }
}
