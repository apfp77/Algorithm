#include <stdio.h>

int sosu(int a)
{
  int i;
  i = 1;
  if (a == 1)
    return (0);
  while (++i < a)
  {
    if (a % i == 0)
      return (0);
    if (i * i > a)
      return (a);
  }
  return (a);
}

int main(void)
{
  int start;
  int end;
  scanf("%d %d", &start, &end);
  int su = end - start;
  int arr[su];
  int arr_index;
  int buf;
  
  arr_index = 0;
  while (start <= end)
  {
    buf = sosu(start);
    if (buf != 0)
    {
      arr[arr_index] = buf;
      arr_index++;
    }
    start++;
  }
  buf = -1;
  while (++buf < arr_index)
    printf("%d\n", arr[buf]);
  return (0);
}