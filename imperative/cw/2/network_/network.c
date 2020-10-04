#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ! Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ! Helper constants
const char *__LIST_END__ = "LIST_END";
#define LIST_END (char *)__LIST_END__

// ? Holds the value stored at an index in a list
typedef struct ListItem
{
  // * The item stored in this list item
  void *data;
  // * The pointer to this item's predecessor
  struct ListItem *prev;
  // * The pointer to this item's successor
  struct ListItem *next;
  // * Size of data
  int elSize;
} ListItem;

// ? Create a new list item
ListItem *listItemNew(int bytes, void *dataPtr, int isPtr);
// ? Link a list item with a successor
void listItemLink(ListItem *item, ListItem *next);
// ? Unlink a list item with its successor
void listItemUnlink(ListItem *item);
// ? Insert a list item before a predecessor
void listItemInsert(ListItem *item, ListItem *next);
// ? Un-insert a list item from its successor
ListItem *listItemUnsert(ListItem *item);
// ? Sets the value stored in an item
void listItemSet(ListItem *item, void *data, int isPtr);
// ? Return the value stored in an item
void *listItemGet(ListItem *item);
// ? Free the list item
void listItemFree(ListItem *item);

ListItem *listItemNew(int bytes, void *dataPtr, int isPtr)
{
  void *src = malloc(bytes);

  if (isPtr)
    memcpy(src, dataPtr, bytes);
  else
    memcpy(src, &dataPtr, bytes);

  ListItem *item = malloc(sizeof(ListItem));

  item->next = item;
  item->prev = item;
  item->elSize = bytes;
  item->data = src;

  return item;
}

void listItemLink(ListItem *item, ListItem *next)
{
  next->prev = item;
  item->next = next;
}

void listItemUnlink(ListItem *item)
{
  ListItem *next = item->next;
  item->next = item;
  // item->prev = item;
  next->prev = item->prev;
}

void listItemInsert(ListItem *item, ListItem *next)
{
  ListItem *prev = next->prev;
  listItemLink(item, next);
  listItemLink(prev, item);
}

ListItem *listItemUnsert(ListItem *item)
{
  ListItem *next = item->next;
  ListItem *prev = item->prev;
  listItemUnlink(item);
  listItemLink(prev, next);
  return item;
}

void listItemSet(ListItem *item, void *data, int isPtr)
{
  if (isPtr)
    memcpy(item->data, data, item->elSize);
  else
    memcpy(item->data, &data, item->elSize);
}

void *listItemGet(ListItem *item)
{
  return item->data;
}

#define listItemGetCast(type, item) *(type)listItemGet(item)

void listItemFree(ListItem *item)
{
  free(item->data);
  free(item);
}

typedef struct List
{
  ListItem *end;
} List;

// ? Create a new list
List *listNew();
// ? Push an item to the start of the list
void listPush(List *list, int bytes, void *data, int isPtr);
// ? Push an item to the end of the list
void listAppend(List *list, int bytes, void *data, int isPtr);
// ? Remove an item from the start of the list
ListItem *listUnpush(List *list);
// ? Remove an item from the end of the list
ListItem *listPop(List *list);
// ? Insert an item at index `i`
void listInsert(List *list, int bytes, void *data, int isPtr, int i);
// ? Remove and return an item from index `i`
ListItem *listUnsert(List *list, int i);
// ? Get an item from a list
ListItem *listGetItem(List *list, int i);
// ? Set an item from a list
void listSetItem(List *list, int i, void *data, int isPtr);
// ? Get the length of the list
int listLength(List *list);
// ? Free the memory used by the list
void listFree(List *list);

// ! ------------
// ! List methods
// ! ------------

List *listNew()
{
  List *list = malloc(sizeof(List));
  list->end = listItemNew(8, LIST_END, 1);
  return list;
}

void listPush(List *list, int bytes, void *data, int isPtr)
{
  ListItem *item = listItemNew(bytes, data, isPtr);
  listItemInsert(item, list->end->next);
}

void listAppend(List *list, int bytes, void *data, int isPtr)
{
  ListItem *item = listItemNew(bytes, data, isPtr);
  listItemInsert(item, list->end);
}

ListItem *listUnpush(List *list)
{
  return listItemUnsert(list->end->next);
}

ListItem *listPop(List *list)
{
  return listItemUnsert(list->end->prev);
}

void _listInsert(ListItem *item, ListItem *next, int i)
{
  if (i == 0)
    listItemInsert(item, next);
  else
    _listInsert(item, next->next, --i);
}

void listInsert(List *list, int bytes, void *data, int isPtr, int i)
{
  ListItem *item = listItemNew(bytes, data, isPtr);
  _listInsert(item, list->end->next, i);
}

ListItem *_listUnsert(ListItem *next, int i)
{
  if (i == 0)
    return listItemUnsert(next);
  else
    return _listUnsert(next->next, --i);
}

ListItem *listUnsert(List *list, int i)
{
  return _listUnsert(list->end->next, i);
}

ListItem *_listGetItem(ListItem *item, int i)
{
  if (i == 0)
    return item;
  else
    return _listGetItem(item->next, --i);
}

ListItem *listGetItem(List *list, int i)
{
  return _listGetItem(list->end->next, i);
}

#define listCastItem(type, list, i) listItemGetCast(type, listGetItem(list, i))

void _listSetItem(ListItem *item, void *data, int isPtr, int i)
{
  if (i == 0)
    listItemSet(item, data, isPtr);
  else
    _listSetItem(item->next, data, isPtr, --i);
}

void listSetItem(List *list, int i, void *data, int isPtr)
{
  _listSetItem(list->end->next, data, isPtr, i);
}

int _listLength(List *list, ListItem *item, int n)
{
  if (list->end == item)
    return n;
  else
    return _listLength(list, item->next, ++n);
}

int listLength(List *list)
{
  return _listLength(list, list->end->next, 0);
}

void listFree(List *list)
{
  while (list->end != list->end->next)
  {
    listItemFree(listPop(list));
  }

  listItemFree(list->end);
  free(list);
}

void listAssert(int line, int expr)
{
  if (expr)
    return;
  printf("Fault on line %d\n", line);
}

void testListNew()
{
  List *l = listNew();
  listAssert(__LINE__, l->end == l->end->next);
  listAssert(__LINE__, l->end == l->end->prev);
  listAssert(__LINE__, listLength(l) == 0);
  listFree(l);
}

void testListPush()
{
  List *l = listNew();

  listPush(l, 8, (void *)2, 0);
  listPush(l, 8, (void *)1, 0);
  listPush(l, 8, (void *)0, 0);

  listAssert(__LINE__, listItemGetCast(int *, l->end->next) == 0);
  listAssert(__LINE__, listItemGetCast(int *, l->end->next->next) == 1);
  listAssert(__LINE__, listItemGetCast(int *, l->end->next->next->next) == 2);
  listAssert(__LINE__, listItemGetCast(char *, l->end->next->next->next->next) == *LIST_END);

  listFree(l);
}

void testListAppend()
{
  List *l = listNew();

  listAppend(l, 8, (void *)0, 0);
  listAppend(l, 8, (void *)1, 0);
  listAppend(l, 8, (void *)2, 0);

  listAssert(__LINE__, listItemGetCast(int *, l->end->next) == 0);
  listAssert(__LINE__, listItemGetCast(int *, l->end->next->next) == 1);
  listAssert(__LINE__, listItemGetCast(int *, l->end->next->next->next) == 2);
  listAssert(__LINE__, listItemGetCast(char *, l->end->next->next->next->next) == *LIST_END);

  listFree(l);
}

void testListInsertUnsert()
{
  List *l = listNew();

  listAppend(l, 8, (void *)0, 0);
  listAppend(l, 8, (void *)1, 0);
  listAppend(l, 8, (void *)3, 0);

  listInsert(l, 8, (void *)2, 0, 2);

  listAssert(__LINE__, listCastItem(int *, l, 0) == 0);
  listAssert(__LINE__, listCastItem(int *, l, 1) == 1);
  listAssert(__LINE__, listCastItem(int *, l, 2) == 2);
  listAssert(__LINE__, listCastItem(int *, l, 3) == 3);

  listItemFree(listUnsert(l, 3));

  listAssert(__LINE__, listCastItem(int *, l, 0) == 0);
  listAssert(__LINE__, listCastItem(int *, l, 1) == 1);
  listAssert(__LINE__, listCastItem(int *, l, 2) == 2);

  listFree(l);
}

void testListLength()
{
  List *l = listNew();
  listAssert(__LINE__, listLength(l) == 0);
  listPush(l, 6, "Hello", 1);
  listAssert(__LINE__, listLength(l) == 1);
  listAppend(l, 7, "World!", 1);
  listAssert(__LINE__, listLength(l) == 2);
  listFree(l);
}

void testList()
{
  testListNew();
  testListPush();
  testListAppend();
  testListInsertUnsert();
  testListLength();
}

// ? A single point in the network
typedef struct NetNode NetNode;
// ? A connection between nodes in the network
typedef struct NetEdge NetEdge;

struct NetNode
{
  char *name;
  List *edges;
};

struct NetEdge
{
  NetNode *a;
  NetNode *b;
  int weight;
};

// ! Node prototypes

// ? Create a new node
NetNode *nodeNew(char *name);
// ? Free the memory used by a node
void nodeFree(NetNode *node);
// ? How many siblings?
int nodeValency(NetNode *node);
// ? Connect two nodes with an edge
NetEdge *nodeConnect(NetNode *a, NetNode *b, int weight, int direction);

// ! Edge prototypes

// ? Create a new edge
NetEdge *edgeNew(NetNode *a, NetNode *b, int weight);
// ? Dissociate the edge from a node
void edgeDissociate(NetEdge *edge, NetNode *node);
// ? Free the edge
void edgeFree(NetEdge *edge);

// ! Node implementation

NetNode *nodeNew(char *name)
{
  NetNode *node = (NetNode *)malloc(sizeof(NetNode));
  node->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  node->edges = listNew();
  strcpy(node->name, name);
  return node;
}

void nodeFree(NetNode *node)
{
  for (int e = 0; e < listLength(node->edges); e++)
  {
    NetEdge *edge = (NetEdge *)(listPop(node->edges)->data);
    edgeFree(edge);
  }
  /* edgeFree(&listCastItem(NetEdge *, node->edges, e)) */;

  listFree(node->edges);
  free(node->name);
  free(node);
}

int nodeValency(NetNode *node)
{
  return listLength(node->edges);
}

NetEdge *nodeConnect(NetNode *a, NetNode *b, int weight, int direction)
{
  NetEdge *edge;

  switch (direction)
  {
  case -1:
    printf("Appending %s->%s|%d\n", b->name, a->name, weight);
    edge = edgeNew(b, a, weight);
    listAppend(b->edges, sizeof(NetEdge *), edge, 1);
    break;
  case 1:
    printf("Appending %s->%s|%d\n", a->name, b->name, weight);
    edge = edgeNew(a, b, weight);
    listAppend(a->edges, sizeof(NetEdge *), edge, 1);
    break;
  case 0:
  default:
    printf("Dual connect: %s==%s|%d\n", a->name, b->name, weight);
    edge = nodeConnect(a, b, weight, 1);
    nodeConnect(a, b, weight, -1);
    break;
  }

  return edge;
}

// ! Edge implementation

NetEdge *edgeNew(NetNode *a, NetNode *b, int weight)
{
  NetEdge *edge = (NetEdge *)malloc(sizeof(NetEdge));
  edge->a = a;
  edge->b = b;
  edge->weight = weight;
  return edge;
}

void edgeDissociate(NetEdge *edge, NetNode *node)
{
  List *edges = node->edges;
  ListItem *cursor = edges->end->next;

  if (!node)
    return;

  int i = 0;

  while (cursor != edges->end)
  {
    if (memcmp(&listCastItem(NetEdge *, edges, i), edge, sizeof(NetEdge)) == 0)
    {
      printf("Edge connected to %s", node->name);
      listItemFree(listUnsert(edges, i));
      break;
    }

    i++;
  }
}

void edgeFree(NetEdge *edge)
{
  // edgeDissociate(edge, edge->a);
  // edgeDissociate(edge, edge->b);
  free(edge);
}

void nodeAssert(int line, int expr)
{
  if (expr)
    return;
  fprintf(stderr, "Fault on line %d\n", line);
  exit(1);
}

void testNodeNew()
{
  NetNode *node = nodeNew("Charlie");
  nodeAssert(__LINE__, strcmp(node->name, "Charlie") == 0);
  nodeFree(node);
}

void testNodeValency()
{
  NetNode *node = nodeNew("Dave");
  nodeAssert(__LINE__, nodeValency(node) == 0);

  NetNode *nde2 = nodeNew("Sarah");

  nodeConnect(node, nde2, 10, 0);

  nodeAssert(__LINE__, nodeValency(node) == 1);

  nodeFree(node);
  // nodeFree(nde2);
}

void testNodeConnect()
{
  NetNode *n1 = nodeNew("Jacob");
  NetNode *n2 = nodeNew("Simon");

  nodeConnect(n1, n2, 5, 0);

  NetEdge *n1edge = &listCastItem(NetEdge *, n1->edges, 0);
  NetEdge *n2edge = &listCastItem(NetEdge *, n2->edges, 0);
}

void testElements()
{
  testNodeNew();
  testNodeValency();
  testNodeConnect();
}

void test()
{
  testList();
  testElements();
}

int main(int n, char *args[])
{
  setbuf(stdout, NULL);

  if (n == 1)
    test();

  List *nodes = listNew();
  listFree(nodes);
}
