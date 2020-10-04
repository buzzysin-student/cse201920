#include "trees.h"

int main()
{
  // * Trees!

  // ? Trees have a starting node that branches children nodes
  // *       Parent
  // *        /  \
  // *   Child   Child
  // *
  // * etc, etc...

  // ? A tree is sorted if any node in the left subtree must be smaller
  // ? than its own key, and any node in the right subtree must be larger

  // ! A KEY CAN ONLY APPEAR AT MOST ONCE IN THE TREE!

  TreeNode *n = node_new(1);

  node_free(n);

  return 0;
}
