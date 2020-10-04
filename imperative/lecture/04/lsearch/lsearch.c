#include <stdbool.h>
#include <stdio.h>

intlinearSearch1(char c, int n, char a[n])
{
  int result = -1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == c)
      result = i;
  }
  return result;
}

int lsearch2(char c, int n, char a[n])
{
  int result = -1;

  //* This adds a level of complexity - the array
  //* may not iterate through the entire contents
  for (int i = 0; i < n; i++)
  {
    if (a[i] == c)
      return i;
  }
  return result;
}

int lsearch3(char c, int n, char a[n])
{
  int result = -1;
  int found = 0;

  //* This is going to be more predictable behaviour
  //* based on the condition
  for (int i = 0; (i < n) && (!found); i++)
  {
    if (a[i] == c)
    {
      result = i;
      found = 1;
    }
  }
  return result;
}

// Find (first) index of c in a or return -1 if not found
int linearSearch4(char c, int n, char a[n])
{
  int result = -1;
  bool found = false;
  for (inti = 0; (i < n) && (!found); i++)
  {
    if (a[i] == c)
    {
      result = i;
      found = true;
    }
  }
  return result;
}

int main(int n, char *args[])
{
  return 0;
}