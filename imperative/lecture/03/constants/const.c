/* Define the boundary constants */
const int FIRST_BOUNDARY = 70;
const int SECOND_BOUNDARY = 50;
const int THIRD_BOUNDARY = 40;

/* Calculate the grade mark */
int grade(int mark);

int main()
{
  int mark;
  printf("Enter your mark: ");
  scanf("%d", &mark);
  printf("Your grade is %d", grade(mark));

  return 0;
}

int grade(int mark)
{
  int grade;
  if (mark >= FIRST_BOUNDARY)
    grade = 1;
  else if (mark >= SECOND_BOUNDARY)
    grade = 2;
  else if (mark >= THIRD_BOUNDARY)
    grade = 3;
  else
    grade = 4;

  return grade;
}