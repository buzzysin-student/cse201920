int main(void)
{
  char *s = malloc(4); // * A persistent version of char[4]
  strcpy(s, "cat");
  printf("%s\n", s);
  free(s); // * Memory must be freed after use

  /* 
   * malloc searches for the best gap in the heap for the size

   ? free merges gaps in the memory

   ? BOTH use a header at the start of allocations that contain 
   ? the metadata of the allocation that organises the structure
   ? of the memory
   */

  /**
   * ! FAULTY CODE
   * char *s = malloc(4);
   * s = "cat"; 
   * //* THIS IS AN ERROR as *s is no longer a pointer to the allocated heap 
   * //* but instead a POINTER TO STRING CONSTANT
   * printf("%s\n", s); 
   * free(s); //* The original pointer to *s is lost as it was overwritten
   * 
   */

  int *numbers = calloc(10, sizeof(int));

  // ! similar to 
  // int *numbers = malloc(10 * sizeof(int));
  // for (int i = 10; i < 0; i --) { numbers[i - 1] = 0; }

  
  return 0;
}