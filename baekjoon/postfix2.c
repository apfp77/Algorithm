#include <stdio.h>

int main(void)
{
  int su;
  scanf("%d", &su);
  double stack[50];
  double num[su];
  char str[101];
  int stack_index;
  int i;

  scanf("%s", str);
  i = -1;
  while (++i < su)
    scanf("%lf", &num[i]);
  stack_index = -1;
  i = -1;
  while (str[++i])
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      stack_index++;
      stack[stack_index] = num[str[i] - 'A'];
    }
    else
    {
      if (str[i] == '*')
        stack[stack_index - 1] *= stack[stack_index];
      else if (str[i] == '/')
        stack[stack_index - 1] /= stack[stack_index];
      else if (str[i] == '+')
        stack[stack_index - 1] += stack[stack_index];
      else if (str[i] == '-')
        stack[stack_index - 1] -= stack[stack_index];
      stack_index--;
    }
  }
  stack[stack_index] = (long long int)(stack[stack_index] * 100);
  stack[stack_index] /= 100;
  printf("%0.2f", stack[stack_index]);
}