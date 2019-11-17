// ? Libraries
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ? Type definitions

// * An abstract representation of an entity that can
// * have connections/relationships with others like itself
typedef struct Node Node;

// * An abstract entity that models connections between Nodes
// * THEREFORE an edge cannot exist without a node, but not
// * vice versa.
typedef struct Edge Edge;

// * A set of nodes and edges, where not all nodes are necessarily
// * connected by a sequence of edges, but any two edges are linked by
// * a sequence of nodes.
typedef struct Network Network;

// * An implementation of a data structure that contains a sequence of
// * items
typedef struct Sequence Sequence;

// * The value of items inside a sequence
typedef struct SequenceItem SequenceItem;

// ? Struct definitions and methods

// * Nodes

struct Node
{
  // * Identifier for this node
  char *label;
  // * The number of connections to this node
  int valence;
  // * Pointers to edges describing relationships
  struct Edge **connections;
};

Node *nodeNew(char *label);
Node *nodeFree(Node *node);
void nodeConnect(Node *sister);
void nodeDisconnect(Node *sister);

// * Edges

struct Edge
{
  // * Indicative of the strength of the relationship between
  // * nodes
  double weight;
  // * Indicative of the directionality of relationships between
  // * nodes (should be 1 for a->b, -1 for b->a and 0 for a==b)
  int direction;
  // * The pointers to nodes connected at either end of this edge
  struct Node **nodes;
};

// * Sequences

struct SequenceItem
{
  struct SequenceItem *prev;
  void *contents;
  struct SequenceItem *next;
};

SequenceItem *sequenceItemNew(void *src)
{
  SequenceItem *s = (SequenceItem *)malloc(sizeof(SequenceItem));
  s->contents = src;
  s->prev = s;
  s->next = s;
  return s;
}

void sequenceItemFree(SequenceItem *s)
{
  free(s->contents);
  free(s);
}

struct Sequence
{
  SequenceItem *head;
  int count;
  int size;
};

Sequence *sequenceNew(int size)
{
  SequenceItem *head = sequenceItemNew(NULL);
  Sequence *sq = (Sequence *)malloc(sizeof(Sequence));
  sq->count = 0;
  sq->head = head;
  sq->size = size;
  return sq;
}

SequenceItem *sequencePop(Sequence *sq)
{
  SequenceItem *popped = sq->head->prev;

  popped->prev->next = sq->head;
  popped->next->prev = popped->prev;

  sq->count--;

  return popped;
}

SequenceItem *sequenceGet(int n, Sequence *sq)
{
  SequenceItem *target = sq->head->next;
  while (n--)
    target = target->next;

  return target;
}

void sequenceInsertAt(int i, Sequence *sq, SequenceItem *s)
{
  SequenceItem *target = sequenceGet(i, sq);

  s->next = target;
  s->prev = target->prev;

  target->prev->next = s;
  target->prev = s;

  sq->count++;
}

void sequenceAppend(Sequence *sq, SequenceItem *s)
{
  sequenceInsertAt(sq->count, sq, s);
  printf("%d\n", sq->count);
}

void sequencePush(Sequence *sq, SequenceItem *s)
{
  sequenceInsertAt(0, sq, s);
}

void sequenceFree(Sequence *sq)
{
  while (sq->head != sq->head->next)
  {
    fprintf(stderr, "Original: %p\n", (void *)sq->head->prev);
    SequenceItem *s = sequencePop(sq);
    fprintf(stderr, "Popped:   %p\n", (void *)s);

    sequenceItemFree(s);
  }

  free(sq->head);
  free(sq);
}
