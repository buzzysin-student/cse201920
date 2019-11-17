#include "network.h"

int main(int n, char *args[])
{
  void *test1 = malloc(sizeof(char));
  void *test2 = malloc(sizeof(char));
  SequenceItem *s1 = sequenceItemNew(test1);
  SequenceItem *s2 = sequenceItemNew(test2);
  Sequence *s = sequenceNew(1);

  sequenceAppend(s, s1);
  sequenceAppend(s, s2);

  sequenceFree(s);
}
