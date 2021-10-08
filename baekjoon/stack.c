#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
  int i;

  i = -1;
  while (s1[++i] && s1[i] == s2[i]);
  if (s1[i] != s2[i])
    return (1);
  return (0);
}

int main(void)
{
  int su;
  scanf("%d",&su);
  int i;
  char arr[su][6];
  int stack_arr[su];
  int stack_index;
  int print_arr[su];
  int print_index;

  stack_index = 0;
  print_index = 0;
  i = -1;
  while (++i < su)
  {
    scanf("%s", arr[i]);
    if (ft_strcmp(arr[i], "push") == 0 || ft_strcmp(arr[i], "PUSH") == 0)
      {
        scanf("%d", &stack_arr[stack_index]);
        stack_index++;
      }
    else if (ft_strcmp(arr[i], "pop") == 0 || ft_strcmp(arr[i], "POP") == 0)
    {
      if (stack_index == 0)
      {
        print_arr[print_index] = -1;
        print_index++;
        continue;
      }
      stack_index--;
      print_arr[print_index]=stack_arr[stack_index];
      print_index++;
    }
    else if (ft_strcmp(arr[i], "top") == 0 || ft_strcmp(arr[i], "TOP") == 0)
    {
      if (stack_index == 0)
        print_arr[print_index] = -1;
      else
        print_arr[print_index]=stack_arr[stack_index -1];
      print_index++;
    }
    else if (ft_strcmp(arr[i], "empty") == 0 || ft_strcmp(arr[i], "EMPTY") == 0)
    {
      if (stack_index == 0)
        print_arr[print_index] = 1;
      else
        print_arr[print_index] = 0;
      print_index++;
    }
    else if (ft_strcmp(arr[i], "size") == 0 || ft_strcmp(arr[i], "SIZE") == 0)
    {
      print_arr[print_index] = stack_index;
      print_index++;
    }
  }
  i = -1;
  while (++i < print_index)
    printf("%d\n", print_arr[i]);
  return (0);
}