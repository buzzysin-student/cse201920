#include "networklist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __NELEM_H__

#define __NELEM_H__

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
  // List *edges = node->edges;
  // ListItem *cursor = edges->end->next;

  // if (!node)
  //   return;

  // int i = 0;

  // while (cursor != edges->end)
  // {
  //   if (memcmp(&listCastItem(NetEdge *, edges, i), edge, sizeof(NetEdge)) == 0)
  //   {
  //     printf("Edge connected to %s", node->name);
  //     listItemFree(listUnsert(edges, i));
  //     break;
  //   }

  //   i++;
  // }
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

#endif
