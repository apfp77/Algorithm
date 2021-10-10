#include <stdio.h>

int main(void)
{
  int su;
  scanf("%d", &su);
  int stack[su];
  int stack_index;
  int result;
  int i;

  stack_index = 0;
  i = -1;
  while (++i < su)
  {
    scanf("%d", &stack[stack_index]);
    if (stack[stack_index] == 0 && stack_index > 0)
    {
      stack_index-= 2;
    }
    else if (stack[stack_index] == 0 && stack_index == 0)
      stack_index--;
    stack_index++;
  }
  i = -1;
  result = 0;
  while (++i < stack_index)
  {
    result += stack[i];    
  }
  printf("%d", result);
}