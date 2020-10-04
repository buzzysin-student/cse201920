#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;
typedef char **strings;
typedef int *ints;
typedef int state;

enum STATES
{
  STATE_NODE_BEFORE,
  STATE_NODE_DIRECTION,
  STATE_NODE_AFTER,
  STATE_EDGE_WEIGHT,
  STATE_END,
  STATE_INVALID
};

int _strcnt(string s, string find, int cnt)
{
  if (strlen(s) < strlen(find))
    return cnt;
  else if (strncmp(s, find, strlen(find)) == 0)
    return _strcnt(++s, find, ++cnt);
  else
    return _strcnt(++s, find, cnt);
}

int strcnt(string s, string find)
{
  return _strcnt(s, find, 0);
}

char *strstrs(string s, int n, strings ss)
{
  for (int i = 0; i < n; i++)
  {
    printf("Looking at index: %d, string: %s\n", i, ss[i]);
    if (strcmp(s, ss[i]) == 0)
    {
      return ss[i];
    }
  }

  return -1;
}

string strnew(string t)
{
  string s = malloc(sizeof(char) * (1 + strlen(t)));
  s[0] = 0;
  strcat(s, t);
  return s;
}

int stralpha(char c)
{
  printf("Is %c alphanumeric?\n", c);
  return (c >= 'A' && c <= 'Z') ||
         (c >= 'a' && c <= 'z') ||
         (c >= '0' && c <= '9');
}

int strarrow(string c)
{
  return *c == '-' ||
         *c == '=' ||
         *c == '>' ||
         *c == '<';
}

int strnum(char c)
{
  printf("Is %c numeric?\n", c);
  return stralpha(c) && (c >= '0' && c <= '9');
}

int strsindex(int n, strings ss, string s)
{
  if (n == -1)
    return -1;
  else if (strcmp(ss[n - 1], s) == 0)
    return n - 1;
  else
    return strsindex(--n, ss, s);
}

void test()
{
  exit(0);
}

void buildNetwork(string buildText)
{
  int conns = strcnt(buildText, ",") + 1;
  int maxconns = conns * 2;
  char *cursor = buildText;
  strings names = malloc(sizeof(string) * maxconns);
  int namecnt = 0;
  ints matrix[maxconns][maxconns];

  state STATE = STATE_NODE_BEFORE;

  while (STATE < STATE_END)
  {
    char nodeA[20];
    nodeA[0] = 0;
    char nodeB[20];
    nodeB[0] = 0;
    int edgeDir = 0;
    int edgeWgt = 1;

    while (STATE == STATE_NODE_BEFORE)
    {
      while (stralpha(*cursor))
      {
        printf("Char: %c\n", *cursor);
        strncat(nodeA, cursor, 1);
        cursor++;
      }
      STATE = STATE_NODE_DIRECTION;
    }

    while (STATE == STATE_NODE_DIRECTION)
    {
      printf("Checking %2s\n", cursor);

      if (strncmp(cursor, "->", 2) == 0)
        edgeDir = 1;
      else if (strncmp(cursor, "<-", 2) == 0)
        edgeDir = -1;
      else if (strncmp(cursor, "==", 2) == 0)
        edgeDir = 0;
      else
      {
        STATE = STATE_INVALID;
        break;
      }

      printf("Direction: %d\n", edgeDir);

      STATE = STATE_NODE_AFTER;
      cursor += 2;
    }

    while (STATE == STATE_NODE_AFTER)
    {
      while (stralpha(*cursor))
      {
        printf("Char: %c\n", *cursor);
        strncat(nodeB, cursor, 1);
        cursor++;
      }

      if ((int)strstrs(nodeA, namecnt, names) == -1)
      {
        names[namecnt] = malloc(sizeof(string) * (strlen(nodeA) + 1));
        strcpy(names[namecnt], nodeA);
        printf("Added node %s\n", nodeA);
        namecnt++;
      }

      if ((int)strstrs(nodeB, namecnt, names) == -1)
      {
        names[namecnt] = malloc(sizeof(string) * (strlen(nodeB) + 1));
        strcpy(names[namecnt], nodeB);
        printf("Added node %s\n", nodeB);
        namecnt++;
      }

      if (*cursor == 0)
        STATE = STATE_END;
      else
        STATE = STATE_EDGE_WEIGHT;

      cursor++;
    }

    while (STATE == STATE_EDGE_WEIGHT)
    {
      char strweight[20];
      int breakindex = strstr(cursor, ",") - cursor;

      if (breakindex <= 0)
        breakindex = (strstr(cursor, "") - cursor);

      strncpy(strweight, cursor, (int)breakindex);
      edgeWgt = atoi(strweight);

      printf("%d\n", (int)*cursor);

      cursor += (int)breakindex;

      if (*cursor == '\0')
        STATE = STATE_END;
      else if (stralpha(*cursor))
      {
        STATE = STATE_NODE_BEFORE;
      }
    }
  }

}

void startNetwork(string buildText)
{
  buildNetwork(buildText);
}

int main(int n, strings args)
{
  fflush(stdout);

  if (n == 1)
    test();

  startNetwork(args[1]);
}
