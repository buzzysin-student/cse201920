/* A header file outlining the structure of the Game */

#include "node.h"

// ! DEFINITIONS
#define __GAME_BORDER_CHAR '='
#define __GAME_BORDER_STRING "="
#define __GAME_MAX_REPR 8
#define __GAME_REPR_STRINGS                \
  {                                        \
    " ", ".", "*", "^", "$", "!", "'", "#" \
  }
const char GAME_REPR_STRINGS[__GAME_MAX_REPR][2] = __GAME_REPR_STRINGS;
// ! DEFINITIONS END

typedef struct Game
{
  // ? The dimensions of the game
  int x, y;

  // ? A 2D array of pointers to nodes
  Node ***node_field;

} Game;

typedef struct GameCoord
{
  // ? The position of something in the game
  int x, y;
} GameCoord;

////////////////////////////////////////
// * NON-STRUCT UTITLITY PROTOTYPES * //
////////////////////////////////////////

void game_print(Game *g);
void game_tick(Game *g);
int game_cyclic_row(Game *g, int y);
int game_cyclic_col(Game *g, int x);

GameCoord **game_coords_siblings(Game *g, int x, int y);
void game_coords_siblings_destroy(GameCoord **gcs);
Node **game_siblings(Game *g, int x, int y);

void game_death_round(Game *next, Game *first);
void game_birth_round(Game *next, Game *first);

void game_field_copy(Game *dest, const Game *src);
char *game_repr(int id);

///////////////////////////////////
// * STRUCT BUILDER PROTOTYPES * //
///////////////////////////////////

Game *game_new(int x, int y);
void game_destroy(Game *g);

void game_node_set(Game *g, int x, int y, Node *n);
void game_node_reset(Game *g, int x, int y);

////////////////////////////////////
// * STRUCT BUILDER DEFINITIONS * //
////////////////////////////////////

// * Create a new Game with y rows and x columns
Game *game_new(int x, int y)
{
  Game *g = malloc(sizeof(Game));
  g->node_field = malloc(sizeof(Node **) * y);

  for (int i = 0; i < y; i++)
  {
    g->node_field[i] = malloc(sizeof(Node *) * x);

    for (int j = 0; j < x; j++)
      g->node_field[i][j] = node_empty();
  }

  g->x = x;
  g->y = y;

  return g;
}

// * Clear memory used by a game
void game_destroy(Game *g)
{
  for (int i = 0; i < g->y; i++)
  {
    for (int j = 0; j < g->x; j++)
      node_destroy(g->node_field[i][j]);

    free(g->node_field[i]);
  }

  free(g->node_field);
  free(g);
}

// * Set a Node in the Game's Node field
void game_node_set(Game *g, int x, int y, Node *n)
{
  node_copy(g->node_field[y][x], n);
}

// * Clear a Node in the Game's Node field
void game_node_reset(Game *g, int x, int y)
{
  node_reset(g->node_field[y][x]);
}

/////////////////////////////////////////
// * NON-STRUCT UTITLITY DEFINITIONS * //
/////////////////////////////////////////

void game_print(Game *g)
{
  int outer_border_x = g->x + 2;

  char x_border[outer_border_x + 1];

  for (int i = 0; i < outer_border_x; i++)
    x_border[i] = __GAME_BORDER_CHAR;

  x_border[outer_border_x] = '\0';

  printf("%s\n", x_border);
  for (int j = 0; j < g->y; j++)
  {
    printf("%s", __GAME_BORDER_STRING);
    for (int k = 0; k < g->x; k++)
    {
      printf("%s", game_repr(g->node_field[j][k]->id));
    }
    printf("%s\n", __GAME_BORDER_STRING);
  }
  printf("%s\n", x_border);
}

void game_tick(Game *g)
{
  Game *h = game_new(g->x, g->y);

  game_death_round(h, g);
  game_birth_round(h, g);

  game_field_copy(g, h);

  game_destroy(h);
}

void game_run(Game *g, int iterations)
{
  while (iterations)
  {
    game_print(g);

    printf("%c[1;1H", (char)27);
    fflush(stdout);

    system("sleep 0.5");

    game_tick(g);
    iterations--;
  }

  printf("%c[2J", 27);
}

int game_cyclic_row(Game *g, int y)
{
  y %= g->y;
  y += (y < 0 ? g->y : 0);
  return y;
}

int game_cyclic_col(Game *g, int x)
{
  x %= g->x;
  x += (x < 0 ? g->x : 0);
  return x;
}

GameCoord **game_coords_siblings(Game *g, int x, int y)
{
  int sib_count = 0;

  GameCoord **siblings = malloc(sizeof(GameCoord *) * 8);

  for (int i = 0; i < __NODE_SIBLING_COUNT; i++)
    siblings[i] = malloc(sizeof(GameCoord));

  for (int j = -1; j < 2; j++)
    for (int k = -1; k < 2; k++)
      if (!(k == 0 && j == 0))
        *siblings[sib_count++] = (GameCoord){game_cyclic_col(g, x + k), game_cyclic_row(g, y + j)};

  return siblings;
}

void game_coords_siblings_destroy(GameCoord **gcs)
{
  for (int i = 0; i < __NODE_SIBLING_COUNT; i++)
    free(gcs[i]);

  free(gcs);
}

Node **game_siblings(Game *g, int x, int y)
{
  GameCoord **siblings_coords = game_coords_siblings(g, x, y);
  Node **siblings = malloc(sizeof(Node *) * 8);

  for (int i = 0; i < __NODE_SIBLING_COUNT; i++)
  {
    node_copy(siblings[i], g->node_field[siblings_coords[i]->y][siblings_coords[i]->x]);
  }

  return siblings;
}

void game_death_round(Game *next, Game *first)
{
  for (int i = 0; i < next->y; i++)
  {
    for (int j = 0; j < next->x; j++)
    {
      Node *n = node_empty();
      node_copy(n, first->node_field[i][j]);

      if (n->lifecycle == 0)
      {
        game_node_reset(next, j, i);
      }

      node_destroy(n);
    }
  }
}

void game_birth_round(Game *next, Game *first)
{
  for (int i = 0; i < next->y; i++)
  {
    for (int j = 0; j < next->x; j++)
    {
      Node *n = node_empty();
      node_copy(n, first->node_field[i][j]);

      if (n->lifecycle)
        n->lifecycle--;

      // printf("Lifecycle = %d\n", n->lifecycle);

      if (n->will_reproduce)
      {
        GameCoord **sibling_coords = game_coords_siblings(first, j, i);

        for (int k = 0; k < __NODE_SIBLING_COUNT; k++)
        {
          int sib_x = sibling_coords[k]->x;
          int sib_y = sibling_coords[k]->y;

          Node *host = node_empty();
          node_copy(host, next->node_field[sib_y][sib_x]);

          if (n->children[k])
          {
            if (host->is_passive || host->lifecycle == 0 || host->id == n->id)
            {
              game_node_set(next, sib_x, sib_y, n);
            }
            else if (host->is_passive == n->is_passive)
            {
              game_node_reset(next, sib_x, sib_y);
            }
          }

          node_destroy(host);
        }

        game_coords_siblings_destroy(sibling_coords);
      }

      node_destroy(n);
    }
  }
}

void game_field_copy(Game *dest, const Game *src)
{
  for (int i = 0; i < src->y; i++)
  {
    for (int j = 0; j < src->x; j++)
    {
      Node *cpy = node_empty();
      node_copy(cpy, src->node_field[i][j]);
      game_node_set(dest, j, i, cpy);
      node_destroy(cpy);
    }
  }
}

char *game_repr(int id)
{
  return GAME_REPR_STRINGS[id];
}