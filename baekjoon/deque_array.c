#include <stdio.h>

int d_i = -1;
int d[10001] = {0,};

int ft_strcmp(char *s1, char *s2)
{
  int i;

  i = -1;
  while (s1[++i] && s1[i] == s2[i])
    ;
  if (s1[i] != s2[i])
    return (1);
  return (0);
}

void push_front(int x)
{
  int a = ++d_i;
  for (int i = d_i - 1; i >= 0; i--)
  {
    d[a] = d[i];
    a--;
  }
  d[a] = x;
}

void push_back(int x)
{
  d[++d_i] = x;
}

int pop_front()
{
  if (d_i == -1)
    return (-1);
  int a = d[0];
  for (int i = 0; i < d_i; i++)
  {
    d[i] = d[i+1];
  }
  d_i--;
  return (a);
}

int pop_back()
{
  if (d_i == -1)
    return (-1);
  d_i--;
  return(d[d_i+1]);
}


int empty()
{
  if (d_i == -1)
    return (1);
  return (0);
}

int front()
{
  if (d_i == -1)
    return (-1);
  return (d[0]);
}

int back()
{
  if (d_i == -1)
    return (-1);
  return (d[d_i]);
}

int main(void)
{
  int su;
  scanf("%d", &su);
  char arr[11];
  int buf;

  int print[su];
  int p_i = -1;

  int i = -1;
  while (++i < su)
  {
    scanf("%s", arr);
    if (!ft_strcmp(arr, "push_front"))
    {
      scanf("%d", &buf);
      push_front(buf);
    }
    
    else if (!ft_strcmp(arr, "push_back"))
    {
      scanf("%d", &buf);
      push_back(buf);
    }

    else if (!ft_strcmp(arr, "pop_front"))
      print[++p_i] = pop_front();

    else if (!ft_strcmp(arr, "pop_back"))
      print[++p_i] = pop_back();

    else if (!ft_strcmp(arr, "size"))
      print[++p_i] = d_i + 1;

    else if (!ft_strcmp(arr, "empty"))
      print[++p_i] = empty();

    else if (!ft_strcmp(arr, "front"))
      print[++p_i] = front();
      
    else if (!ft_strcmp(arr, "back"))
      print[++p_i] = back();
  } 
  i = -1;
  while (++i <= p_i)
    printf("%d\n", print[i]);
}
