/* A header file containing the structs to be used in the Game */

#include "util.h"

// ! DEFINITIONS
#define __NODE_SIBLING_COUNT 8
#define __NODE_CHILDREN_DEFAULT \
  {                             \
    0, 1, 0, 1, 1, 0, 1, 0      \
  }
#define __NODE_SIBLINGS_DEFAULT __NODE_CHILDREN_DEFAULT
#define __NODE_DEATH_DEFAULT 0
#define __NODE_REPRODUCE_DEFAULT 1
#define __NODE_PASSIVE_DEFAULT 1
#define __NODE_CHILDREN_EMPTY \
  {                           \
    0, 0, 0, 0, 0, 0, 0, 0    \
  }
#define __NODE_SIBLINGS_EMPTY __NODE_CHILDREN_EMPTY
// ! DEFINITIONS END

// ? A Node is a single point on the
// ? Game. Its behaviour is determined
// ? by its siblings
typedef struct Node
{
  // ? Each new type of node introduced
  // ? into the Game will have a unique
  // ? identifier attached to the population
  int id;

  // ? An array of pointers Node ids adjacent
  // ? to this Node:
  // ? 1 2 3
  // ? 4 * 5
  // ? 6 7 8
  int *siblings;

  // ? When 0, the Node will survive until
  // ? the next cycle. When 1 the Node will
  // ? die. The Node will try and survive
  // ? by default.
  // TODO: Replace with lifecycle
  //// int lifecycle;

  // ? When 0, the Node will not exhibit its
  // ? reproductive behaviour. When 1 the Node
  // ? will produce children. The Node will try
  // ? and reproduce immediately by default
  int will_reproduce;

  // ? An array of 0s and 1s that determine
  // ? where its children are spawned. For
  // ? example, {0,1,0,1,1,0,1,0} means
  // ? 0 1 0
  // ? 1 x 1
  // ? 0 1 0
  int *children;

  // ! Problem - what about when two Nodes
  // ! of different identifiers want to produce
  // ! children in the same spot?
  // * Solution - make some nodes passive and
  // * some nodes agressive. Examples:
  // * A | B | winner
  // * ---------------
  // * p | p |    -
  // * p | a |    B
  // * a | p |    A
  // * a | a |    -
  // ? All Nodes will be passive by default
  int is_passive;

  // ? Simply how many cycles before a node dies permanently
  int lifecycle;

} Node;

///////////////////////////////////////
// * NON-STRUCT UTILITY PROTOTYPES * //
///////////////////////////////////////

void node_sibling_copy(int *dest, const int *src);

void node_copy(Node *dest, const Node *src);

void node_reset(Node *n);

///////////////////////////////////
// * STRUCT BUILDER PROTOTYPES * //
///////////////////////////////////

Node *node_new(
    int id, int *sibs,
    int lifecycle, int will_reproduce,
    int *children, int is_passive);

Node *node_new_simple(
    int id, int *sibs,
    int *children);

Node *node_empty();

void node_destroy(Node *n);

////////////////////////////////////
// * STRUCT BUILDER DEFINITIONS * //
////////////////////////////////////

// * Create a new Node and return its reference
Node *node_new(
    int id, int *sibs,
    int lifecycle, int will_reproduce,
    int *children, int is_passive)
{
  Node *n = (Node *)malloc(sizeof(Node));

  n->siblings = (int *)malloc(sizeof(int) * 8);
  n->children = (int *)malloc(sizeof(int) * 8);
  node_sibling_copy(n->siblings, sibs);
  node_sibling_copy(n->children, children);

  n->id = id;
  n->lifecycle = lifecycle;
  n->will_reproduce = will_reproduce;
  n->is_passive = is_passive;

  return n;
}

Node *node_new_simple(
    int id, int *sibs,
    int *children)
{
  return node_new(
      id, sibs,
      __NODE_DEATH_DEFAULT,
      __NODE_REPRODUCE_DEFAULT,
      children,
      __NODE_PASSIVE_DEFAULT);
}

Node *node_empty()
{
  int *sibs = malloc(sizeof(int) * 8);
  int *children = malloc(sizeof(int) * 8);
  node_sibling_copy(sibs, (int[8])__NODE_SIBLINGS_EMPTY);
  node_sibling_copy(sibs, (int[8])__NODE_SIBLINGS_EMPTY);

  Node *n = node_new_simple(0, sibs, children);

  n->will_reproduce = 0;
  n->lifecycle = 0;

  free(sibs);
  free(children);

  return n;
}

// * Destroy the Node located at `n`
void node_destroy(Node *n)
{
  if (n->children)
    free(n->children);

  if (n->siblings)
    free(n->siblings);

  free(n);
}

///////////////////////////////////
// * STRUCT UTILITY PROTOTYPES * //
///////////////////////////////////

void node_copy(Node *dest, const Node *src)
{
  node_sibling_copy(dest->siblings, src->siblings);
  node_sibling_copy(dest->children, src->children);

  dest->id = src->id;
  dest->lifecycle = src->lifecycle;
  dest->will_reproduce = src->will_reproduce,
  dest->is_passive = src->is_passive;
}

// * Copy an array related to siblings from a source
void node_sibling_copy(int *dest, const int *src)
{
  for (int i = 0; i < __NODE_SIBLING_COUNT; i++)
    dest[i] = src[i];
}

void node_reset(Node *n)
{
  Node *empty = node_empty();
  node_copy(n, empty);
  node_destroy(empty);
}
