// ! Strucutures will allow you to group types together.
// ! For example -> an avatar in a game may include:
// ! ==> Size
// ! ==> Colour
// ! ==> Position
// ! ==> Speed, ...etc

// ? In C, you can group entities together using the `struct`
// ? keyword
typedef struct item
{
  // A new data type called `struct item`. These two items,
  // `x` and `y` are called `fields` and are order dependant
  // during initialisation.
  int x, y;
} item; // Alias notation

// ? Increase the values of x and y position using dx and dy
// Old signature:
// struct item move(struct item i, int dx, int dy)
void move(item *i, int dx, int dy)
{
  // * Initial code
  // i.x += dx;
  // i.y += dy;

  // * New code
  i->x += dx;
  i->y += dy;

  // ! Structs are PASSED BY VALUE, not be REFERENCE! This makes
  // ! Them quite more useful than an array in different ways

  // Old return statement:
  // return i;
}

typedef struct word
{
  char s[30];
  int count;
} const word;

#include "alias.h"
