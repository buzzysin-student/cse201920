#include <stdio.h>
#include <stdlib.h>

// ? A data structure containing data and a pointer to the
// ? next data
typedef struct StackElement
{
  int value;
  struct StackElement *next;
} StackElement;

// ? A `last-in-first-out` data structure containing StackElements
typedef struct Stack
{
  StackElement *head;
} Stack;

// ? Create a new stack
Stack *stack_new()
{
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->head = NULL;
  return s;
}

// ? Insert a new stack element at the top to of the stack
void stack_push(Stack *stack, int value)
{
  // ? Create a stack element
  StackElement *next = malloc(sizeof(StackElement));
  // ? Assign a value into the stack element
  next->value = value;
  // ? Next element should point to old stack head
  next->next = stack->head;
  // ? Stack head should point to next element
  stack->head = next;
}

// ? Check if stack is empty
int stack_empty(Stack *s)
{
  return (int)(s->head == NULL);
}

// ? Remove the head of the stack and return it
int stack_pop(Stack *s)
{
  // ? Ignore empty stacks
  if (stack_empty(s))
    return -999;

  // ? Get the head of the stack
  StackElement *head = s->head;
  // ? Extract its value
  int result = head->value;
  // ? The new head of the stack is the next element
  s->head = head->next;
  // ? Free the old head
  free(head);
  // ? Return the extracted value
  return result;
}

// ? Clear the memory of the stack
void stack_free(Stack *s)
{
  while (!stack_empty(s))
  {
    printf("%d\n", s->head->value);
    stack_pop(s);
  }

  free(s);
}

int main(void)
{
  Stack *s = stack_new();

  stack_push(s, 1);
  stack_push(s, 2);
  stack_push(s, 3);
  stack_push(s, 2);
  stack_push(s, 1);

  stack_free(s);
}
