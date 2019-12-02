#include "networkelements.h"
#include "networklist.h"

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
