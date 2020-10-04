#include <stdio.h>

double add(double amount, double interestRate)
{
  // Interest = amount saved + bonus based on amount
  amount = amount * (1 + interestRate);

  return amount;
}

int main(void)
{
  // a = amount
  // i = interest
  double a, i;
  // Receive the amount saved.
  printf("Enter saved amount: £");
  scanf("%lf", &a);
  // Receive the interest rate
  printf("Enter the interest rate (%%): ");
  scanf("%lf", &i);
  // Compute the interest
  double total = add(a, i);

  // Display the result
  printf("Adding %.3f%% to £%.2f gives £%.2f\n", i, a, total);

  // Exit the program
  return 0;
}