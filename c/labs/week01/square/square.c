#include <stdio.h>

// The purpose of this program is to take
// in a number as input and produce the q
// square of that number as an output

// i.e. 2 -> 2^2 -> 4

int square(int num)
{
  // Shadowing?
  int square;

  // Multiply the number by itself
  square = num * num;

  // Return the square
  return square;
}

int main(void)
{
  int num = 0;

  // Receive a prompt
  printf("Please type an integer that you want to square: ");
  // Store the variable
  scanf("%d", &num);
  // Display the result
  printf("The number that you squared is: %d\n", square(num));
  // End the program
  return 0;
}
