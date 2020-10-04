int main(void)
{
  // Comparing a for with a while:

  // FOR LOOP
  for (int i = 0; i < 10; i++)
  {
    // Write some code
  }

  // Decreasing
  for (int i = 10; i <= 1; i--)
  {
    // Write some code
  }

  // WHILE LOOP
  int j = 0;
  while (j < 10)
  {
    // Write some code
    j++; // THE CODE MUST MEET THE TERMINATING CONDITION
  }

  // Decreasing
  j = 10;
  while (j >= 1)
  {
    // Write some code
    j--; // THE CODE MUST MEET THE TERMINATING CONDITION
  }

  ///////////////////////////////
  // DO NOT USE THE FOLLOWING! //
  ///////////////////////////////

  /**
   * DO WHILE
   */
  int k = 0;
  do
  {
    // Write some code
    k++;
  } while (k < 10); // Checks at the end is bad practice

  /**
   * GOTO & LABELS 
   */
  int k = 0;
SOME_LABEL:

  if (k < 10)
    goto SOME_LABEL;

  /**
   * BREAK & CONTINUE
   */
  int l = 10;
  while (l >= 1)
  {
    if (l == 5)
    {
      // Write some code
      break; // Exit the loop to the bottom
    }

    if (l == 4)
    {
      continue; // Skip this iteration and restart the loop
    }
  }
}