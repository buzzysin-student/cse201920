
#include <math.h>
#include "../display.h"

#define SNAKE_SIZE 16

#define GAME_SIZE_X 16
#define GAME_SIZE_Y 8

#define WINDOW_SIZE_X SNAKE_SIZE* GAME_SIZE_X
#define WINDOW_SIZE_Y SNAKE_SIZE* GAME_SIZE_Y

#define random(a) (rand() / RAND_MAX) * a
#define random2(a, b) a + random(a - b)

typedef struct GamePosition GamePosition;
typedef struct GameChunk GameChunk;
typedef struct Game Game;

struct GamePosition {
  int x, y;
};

struct GameChunk {
  void* inhabitant;
};

struct Game {
  GameChunk*** chunks;
};

Game* newGame(void* player) {
  Game* game = malloc(sizeof(Game));
  game->chunks = malloc(sizeof(GameChunk*) * GAME_SIZE_Y);

  for (int chunk_row = 0; chunk_row < GAME_SIZE_Y; chunk_row++) {
    game->chunks[chunk_row] = malloc(sizeof(GameChunk) * GAME_SIZE_X);
    for (int chunk = 0; chunk < GAME_SIZE_X; chunk++)
      game->chunks[chunk_row][chunk]->inhabitant = NULL;
  }

  int* playerXY = {random(GAME_SIZE_X), random(GAME_SIZE_Y)};
  int* foodXY = {random(GAME_SIZE_X), random(GAME_SIZE_Y)};

  while ((foodXY[0] == playerXY[0]) && (foodXY[1] == foodXY[1])) {
    foodXY = (int*){random(GAME_SIZE_X), random(GAME_SIZE_Y)};
  }

  while ((foodXY[0] == playerXY[0]) && (foodXY[1] == foodXY[1])) {
    game->chunks[(int)(random(GAME_SIZE_Y))][random(GAME_SIZE_X)] =
        (SnakeFood*)newSnakeFood();
  }

  game->chunks[playerXY[1]][playerXY[0]]->inhabitant = (Snake*)player;

  return game;
};

typedef struct SnakeBody SnakeBody;
typedef struct SnakeFood SnakeFood;
typedef struct Snake Snake;

struct SnakeBody {
  SnakeBody* head;
  SnakeBody* tail;
  int top;
  int bottom;
  GamePosition* position;
};

struct SnakeFood {
  int hunger;
};

struct Snake {
  SnakeBody* body;
  // * N = 0, E = 1, S = 2, W = 3
  int facing;
};

SnakeBody* newSnakeBody() {
  SnakeBody* body = malloc(sizeof(SnakeBody));
  body->head = body;
  body->tail = body;
  body->top = 0;
  body->bottom = 1;
  return body;
};

Snake* newSnake() {
  Snake* snake = malloc(sizeof(Snake));
  snake->body = newSnakeBody();
  return snake;
}

bool runSnake(display* d, void* data, int pressedKey) {
  return (pressedKey == 27);
}

int main() {
  display* d = newDisplay("SNAKE!", WINDOW_SIZE_X, WINDOW_SIZE_Y);
  Snake* player = newSnake();
  Game* game = newGame(player);
  run(d, game, runSnake);
  return 0;
}