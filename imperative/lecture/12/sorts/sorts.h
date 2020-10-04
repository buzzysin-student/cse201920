typedef item item;

struct item
{
  int value;
};

void item_swap(int a, int b, item xs[])
{
  item temp = xs[a];
  xs[a] = xs[b];
  xs[b] = temp;
}