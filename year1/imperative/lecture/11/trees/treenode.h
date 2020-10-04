/**
 * * File containing the structs for trees
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  // * Nodes with keys less than `key` go here
  struct TreeNode *left;
  // * Every key must go at least once
  int key;
  // * Nodes with keys greater than `key` go here
  struct TreeNode *right;
} TreeNode;

// * TreeNode Prototypes

// ? Creates a new node in the tree
TreeNode *node_new(int value);

// ! This definition is flawed as we lose
// ! The pointer to the root node
TreeNode *node_insert_flawed(TreeNode *n, int key);

// ? Inserts a new node into the tree
bool node_insert(TreeNode **n, int key);

// ? Clear the memory that the node is using
void node_free(TreeNode *n);
// * TreeNode Prototypes END

TreeNode *node_new(int value)
{
  TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
  *n = (TreeNode){NULL, value, NULL};
  return n;
}

TreeNode *node_insert_flawed(TreeNode *n, int key)
{
  // * If the node to insert is to empty
  if (n == NULL)
    // * Create a new node
    n = node_new(key);

  // * If the new key is less than the
  // * current key
  else if (key < n->key)
    // * Insert into the left
    n->left = node_insert_flawed(n->left, key);

  // * Otherwise
  else if (key > n->key)
    // * Insert into the right
    n->right = node_insert_flawed(n->right, key);

  return n;
}

bool node_insert(TreeNode **n, int key)
{
  if (*n == NULL)
  {
    *n = node_new(key);
    return true;
  }

  else if (key < (*n)->key)
    // * To fix the error above, pass a reference to the
    // * node's left pointer
    return node_insert(&(*n)->left, key);
  else if (key > (*n)->key)
    // * etc., etc...
    return node_insert(&(*n)->right, key);

  return false;
}

void node_free(TreeNode *n)
{
  free(n);
}
