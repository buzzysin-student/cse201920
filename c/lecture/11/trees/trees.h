#include "treenode.h"

typedef struct Tree
{
  // * The reference to the root of the tree
  TreeNode *root;
} Tree;

Tree *tree_new(int key)
{
  Tree *t = malloc(sizeof(Tree));
  t->root = node_new(key);
}

bool tree_insert(Tree *t, int key)
{
  // Pass the adress of the tree's root
  return node_insert(&(t->root), key);
}

void tree_free(Tree *t)
{
  // Free the tree recursively
}