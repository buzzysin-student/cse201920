#include <stdlib.h>
#include <assert.h>

typedef struct loop_stack {
  struct loop_stack* n;
  int v;
  struct loop_stack* p;
} loop_stack;

loop_stack* lsnew(int v) {
  loop_stack* ls = (loop_stack*)malloc(sizeof(loop_stack));
  ls->n = NULL;
  ls->v = v;
  ls->p = NULL;
  return ls;
}

void lsfreeitem(loop_stack *ls) {
  assert(ls->p == NULL);
  assert(ls->n == NULL);
  free(ls);
}

loop_stack* lspush(loop_stack *ls, int v) {
  loop_stack *ls2 = lsnew(v);
  ls->n = ls2;
  ls2->p = ls;
  return ls2;
}

loop_stack* lspop(loop_stack *ls) {
  ls->p->n = NULL;
  loop_stack *p = ls->p;
  
  return ls;
}

void lsfreestack(loop_stack *ls) {
  while (ls->p != NULL) {
    lsfreeitem(lspop(ls));
  }

  lsfreeitem(ls);
}
