#include <stdio.h>

int ft_strlen(char *str)
{
  int i;

  i = -1;
  while (str[++i]);
  return (i);
}

int main(void)
{
  char edit[600010];
  char stack[300010];
  int e_i;
  int stack_i;
  int n;
  char buf;
  int i;

  scanf("%s", edit);
  e_i = ft_strlen(edit) - 1;
  stack_i = -1;
  scanf("%d", &n);

  i = -1;
  while (++i < n)
  {
    scanf(" %c", &buf);
    if (e_i < -1)
      e_i = -1;
    if (buf == 'L')
    {
      if (e_i != -1)
      {
        stack[++stack_i] = edit[e_i];
        edit[e_i] = 0;
        e_i--;
      }
    }
    else if (buf == 'D')
    {
      if (stack_i != -1)
      {
        edit[++e_i] = stack[stack_i];
        stack[stack_i] = 0;
        stack_i--;
      }
    }
    else if (buf == 'P')
    {
      scanf(" %c", &buf);
      e_i++;
      edit[e_i] = buf;
    }
    else if (buf == 'B')
    {
      if (e_i != -1)
      {
        edit[e_i] = 0;
        e_i--;
      }
    }
  }
  for (int i = 0; i <= e_i; i++)
    printf("%c", edit[i]);
    
  for (int i = stack_i; i >= 0; i--)
    printf("%c", stack[i]);
}