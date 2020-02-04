#include "lib/game.h"
#include "settings/default.h"

int main(void)
{
  setbuf(stdout, NULL);

  int siblings[8], children[8];
  node_sibling_copy(siblings, NODE_CHILDREN_DEFAULT);
  node_sibling_copy(children, NODE_CHILDREN_DEFAULT);

  int sib2[8], chd2[8] = {1,1,1,0,0,1,1,1};
  node_sibling_copy(sib2, chd2);

  Node *n1 = node_new_simple(1, siblings, children);
  Node *n2 = node_new(2, sib2, 1, 1, chd2, 0);

  n2->lifecycle = 0;
  n1->lifecycle = 0;
  node_sibling_copy(n1->children, chd2);

  Game *g = game_new(21, 21);

  game_node_set(g, 7, 10, n1);
  game_node_set(g, 14, 10, n2);

  node_destroy(n1);
  node_destroy(n2);

  game_run(g, 20);

  game_destroy(g);

  return 0;
}
