#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int m)
{
  int i;
  
  i = -1;
  while (++i < m)
    printf("%d ", arr[i]);
  printf("\n");
}

void arr_zero(int *arr, int  m)
{
  int i;

  i = -1;
  while (++i < m)
    arr[i] = 0;
}

void calc(int k, int *check, int m, int n)
{
  static int *arr;
  static int check2 = 0;
  int i;

  i = -1;
  if (check2 == 0)
  {
    arr = (int *)malloc(sizeof(int) * m);
    if (!arr)
      return;
    arr_zero(arr, m);
    check2 = 1;
  }
  if (k == m)
  {
    print(arr, m);
    return;
  }
  while (++i < n)
  {
    if (check[i])
    {
      check[i] = 0;
      arr[k] = i + 1;
      calc(k + 1, check, m, n);
      check[i] = 1;
    }
  }
}

int main(void)
{
  int n;
  int m;
  int *check;
  int i;

  i = -1;
  scanf("%d %d", &n, &m);
  check = (int *)malloc(sizeof(int) * n);
  if (!check)
    return (0);
  while (++i < n)
    check[i] = 1;  
  calc(0, check, m, n);
  free(check);
}