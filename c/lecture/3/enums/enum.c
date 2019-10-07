#include <stdio.h>

// Enumerations defined a series of integers
// when not preinitialised and are constants
// i.e. they cannot be changed after initia-
// lisation.
enum Weekdays
{
  MON, // 0
  TUE, // 1
  WED, // 2
  THU, // ...
  FRI,
  SAT,
  SUN // 6
};

// enumerations can behave like a type
enum Weekdays current = WED;

void dayRoutine(int day)
{
  switch (day)
  {
  case MON:
    printf("Monday");
    break;
  case TUE:
    printf("Tuesday");
    break;
  case WED:
    printf("Wednesday");
    break;
  case THU:
    printf("Thursday");
    break;
  case FRI:
    printf("Friday");
    break;
  case SAT:
    printf("Saturday");
    break;
  default:
    printf("Sunday");
  }
  printf("\n");
}

int main()
{
  dayRoutine(2);
  return 0;
}
