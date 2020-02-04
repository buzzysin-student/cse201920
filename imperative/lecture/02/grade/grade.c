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
  if (mark >= 70)
    grade = 1;
  else if (mark >= 60)
    grade = 2;
  else if (mark >= 50)
    grade = 3;
  else
    grade = 4;

  return grade;
}