enum Types
{
  TYPE_CHAR,
  TYPE_
};

/**
 * * ./visualise char 48
 * ? char - 7 bits +/- => [-128,127]
 * ! 0 0 0 1 1 0 0 0
 */
char *display(char type[], char amount[])
{
}

int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    char type[] = argv[0];
    char amount[] = argv[1];

    display(type, amount);
  }
}