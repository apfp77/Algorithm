#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int m)
{
  for (int i = 0; i < m; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void test(int *arr, int  m)
{
  for (int i = 0; i < m; i++)
    arr[i] = 0;
}

void calc(int k, int *check, int m, int n)
{
  static int *arr;
  static int check2 = 0;
  if (check2 == 0)
  {
    arr = (int *)malloc(sizeof(int) * m);
    if (!arr)
      return;
    test(arr, m);
    check2 = 1;
  }
  if (k == m)
  {
    print(arr, m);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (check[i])
    {
      check[i] = 0;
      arr[k] = i + 1;
      calc(k+1, check, m, n);
      check[i] = 1;
    }
  }
}

int main(void)
{
  int n;
  int m;
  int *check;

  scanf("%d %d", &n, &m);
  check = (int *)malloc(sizeof(int) * n);
  if (!check)
    return (0);
  for (int i = 0; i < n; i++)
    check[i] = 1;
  
  calc(0, check, m, n);
  free(check);
}