#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"



// ? This is the accumulator. It can be used to do things.
int acc;
// ? This is the memory array. It can be used to store things.
char *m;
// ? This is the memory pointer. It can be used to access the memory
int mPtr;
// ? This is the file pointer. It can be used to access the file
FILE *f;
// ? This is the loop stack pointer. It is used for jumps and loops.
char *ls;
// ? This is the program counter. It is used for jumps and loops.
int pc;
// ? This is the accumulator-to-memory-pointer switch.
int sw;

#define MEMLIMIT 100
#define STACKLENGTH strlen(ls) ? strlen(ls) - 1 : strlen(ls)

int EQUAL_CHAR(char *c1, char *c2) {
  return strcmp(c1, c2) == 0;
}

int IGNORE_CHAR(char *c) {
  return 
    EQUAL_CHAR(c, "\n") ||
    EQUAL_CHAR(c, "\r") ||
    EQUAL_CHAR(c, "\0") ||
    EQUAL_CHAR(c, " ");
}

void JUMP() {
  rewind(f);
  int p = 0;
  while (p != pc) {
    char *c = malloc(sizeof(char)* 2);
    c[0] = fgetc(f), c[1] = 0;
    if(! IGNORE_CHAR(c))
      p++;
    free(c);
  }
  ls[STACKLENGTH] = (char)0;
}

void JUMP_LOGIC(char *c, int *i) {
  if (EQUAL_CHAR(c, "Z") && *i == 0)
    ls[STACKLENGTH] = (char)0, pc += 1, JUMP();

  if (EQUAL_CHAR(c, "N") && *i != 0)
    ls[STACKLENGTH] = (char)0, pc += 1, JUMP();
  
  if (EQUAL_CHAR(c, "[")) strcat(ls, (char*)&pc);
  if (EQUAL_CHAR(c, "]")) { 
    if (strlen(ls) == MEMLIMIT - 1) {
      perror("Stack Overflow"), exit(EXIT_FAILURE);
    }
    pc = ls[STACKLENGTH];
    pc -= 1;
  }

  if (EQUAL_CHAR(c, "]")) JUMP();
}

void init(char *file) {
  f = fopen(file, "r"), m = calloc(MEMLIMIT, sizeof(char)), acc = 0; 
  mPtr = 0, pc = 0, ls = calloc(MEMLIMIT, sizeof(char)), sw = 0;
  assert(f != NULL);

  for (int i = 1; i < MEMLIMIT; i++)
    ls[i] = -1;
}

void deinit(){
  free(m);
  fclose(f);
  free(ls);
}

void parse(char *c) {
  int *i = sw == 0 ? &acc: &mPtr;

  if (IGNORE_CHAR(c)) return;

  if (EQUAL_CHAR(c, "*")) sw = !sw;

  if (EQUAL_CHAR(c, "+")) *i += 1;
  if (EQUAL_CHAR(c, "-")) *i -= 1;
  if (EQUAL_CHAR(c, "v")) *i += 5;
  if (EQUAL_CHAR(c, "V")) *i -= 5;
  if (EQUAL_CHAR(c, "x")) *i += 10;
  if (EQUAL_CHAR(c, "X")) *i -= 10;
  if (EQUAL_CHAR(c, "~")) *i = -*i;

  JUMP_LOGIC(c, i);

  if (EQUAL_CHAR(c, "<")) m[mPtr] = acc;
  if (EQUAL_CHAR(c, ">")) acc = m[mPtr];
  if (EQUAL_CHAR(c, "{")) m[mPtr] += acc;
  if (EQUAL_CHAR(c, "}")) acc += m[mPtr];
  if (EQUAL_CHAR(c, "\\")) m[mPtr] -= acc;
  if (EQUAL_CHAR(c, "/")) acc -= m[mPtr];

  if (EQUAL_CHAR(c, "#")) printf("%c", *i);
  if (EQUAL_CHAR(c, "!")) printf("%c", m[mPtr]);

  printf("c = %s, pc = %d, sw = %d, acc = %d, mPtr = %d, m[%d] = %d\n", c, pc, sw, acc, mPtr, mPtr, m[mPtr]);

  printf("ls = ");

  for(int i = 0; i < strlen(ls); i++)
    printf("%d ", ls[i]);

  printf("\n");

  pc++;
}

int main(int argc, char ** argv) {
  if (argc == 2){

    init(argv[1]);

    while (!feof(f)) {
      char *c = malloc(sizeof(char)*2);
      c[0] = fgetc(f) ,c[1] = 0;
      parse(c), free(c);
    }

    deinit();
  }
  return 0;
}
