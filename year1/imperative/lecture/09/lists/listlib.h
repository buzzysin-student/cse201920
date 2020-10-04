// A library is a set of functions and definitions that
// are simple and clear to use

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Constants for use in this library
const int INITIAL_CAPACITY = 8; // capacity of new list
const int GROWTH_RATE = 50;     // in percent of list length
const int FAILURE_CODE = 1;     // exit code at program failure

// The data structure for what will populate the list
typedef int item;

// An abstraction for a variable sized array of integers
typedef struct list
{
  // Current number of items in the list
  int length;
  // Maximum number of items in the list
  int capacity;
  // Pointer to the item array
  item *items;
} list;

typedef char *string;
typedef string *string_arr;

///////////////////////////
/// FUNCTION PROTOTYPES ///
///////////////////////////

// create an empty list and return a pointer to it
list *newList();
// return number of items stored in list
int length(list *l);
// add item n to the end of the list
void add(list *l, item n);
// return item at index i
item get(list *l, int i);
// set item at index i
void set(list *l, int i, item n);
// insert item n before item i
void insert(list *l, int i, item n);
// remove item at position i
void delete (list *l, int i);
// check list is as target
bool check(list *l, int n, item target[n]);
// destroy a list and free all its memory
void freeList(list *l);
// grow a list's size
void expand(list *l);

///////////////////////////////
/// FUNCTION IMPLEMENTATION ///
///////////////////////////////

list *newList()
{
  // ? Create the space necessary to hold the struct
  list *l = malloc(sizeof(list));
  // ? Create the space necessary to hold the list
  item *items = malloc(INITIAL_CAPACITY * sizeof(items));
  // ? Assign the pointers to the object
  *l = (list){0, INITIAL_CAPACITY, items};
  // ? Return the address to the initialised struct
  return l;
}

void freeList(list *l)
{
  free(l->items);
  free(l);
}

item get(list *l, int i)
{
  if (
      // Index is negative
      (i < 0) ||
      // Index is greater than length
      (i >= l->length))
  {
    char msg[100];
    sprintf(msg, "Cannot get element at index %d", i);
    error(msg);
  }

  return l->items[i];
}

void set(list *l, int i, int n)
{
  if (
      // Index is negative
      (i < 0) ||
      // Index is greater than length
      (i >= l->length))
  {
    char msg[100];
    sprintf(msg, "Cannot set element at index %d", i);
    error(msg);
  }

  l->items[i] = n;
}

void add(list *l, item n)
{
  if (l->length >= l->capacity) expand(l);
}

///////////////
/// TESTING ///
///////////////

// check if an expression expr is valid
void assert(int l, bool expr);
// show an error and stop the program
void error(string message);
// The test suite to validate usage of lists
void test();

void assert(int l, bool expr)
{
  if (expr)
    return;
  else
  {
    char msg[100];
    sprintf(msg, "Test failed on line %d", l);
    error(msg);
  }
}

void error(string message)
{
  fprintf(stderr, "List failure: %s", message);
  exit(FAILURE_CODE);
}

void test()
{
  list *l = newList();
}

bool check(list *l, int n, item target[n])
{
  bool ok = true;
  if (l->length != n)
    ok = false;
  if (l->capacity < n)
    ok = false;
  for (int i = 0; i < n; i++)
    if (l->items != target[i])
      ok = false;

  return ok;
}