#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int su;
  scanf("%d", &su);
  int *arr = (int *)malloc(sizeof(int) * su);
  int *stack = (int *)malloc(sizeof(int) * su);
  int *print = (int *)malloc(sizeof(int) * su);
  int arr_index;
  int stack_index;
  int print_index;

  stack_index = -1;
  print_index = 0;
  if (arr == NULL || stack == NULL || print == NULL)
    return (0);
  arr_index = -1;
  while (++arr_index < su)
    scanf("%d", &arr[arr_index]);

  while (--arr_index >= 0)
  {
    while (arr[arr_index] >= stack[stack_index] && stack_index >= 0)
    {
      stack_index--;
    }
    if (stack_index >= 0)
    {
      print[print_index] = stack[stack_index];
    }
    else
      print[print_index] = -1;
    print_index++;
    stack_index++;
    stack[stack_index] = arr[arr_index];
  }
  while (--print_index >= 0)
    printf("%d ", print[print_index]);
  free(arr);
  free(print);
  free(stack);
  stack = NULL;
  arr = NULL;
  print = NULL;
  return (0);
}