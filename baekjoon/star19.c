#include <stdio.h>
#include <stdlib.h>

void star(char **arr, int k, int n)
{
  static int check = 0;

  if (k == n-1)
  {
    arr[k][k] = '*';
    return;
  }
  for (int i = k; i < n; i++)
  {
    arr[k][i] = '*';
    arr[n - 1][i] = '*';
   
    arr[i][k] = '*';
    arr[i][n - 1] = '*';
  }
  check++;
  star(arr, k + 2, n - 2);
}

int main(void)
{
  int n;
  char **arr;
  scanf("%d", &n);
  n = 4 * (n-2) + 5;
  arr = (char **)malloc(sizeof(char *) * n);
  if (!arr)
    return (0);
  for (int i = 0; i < n; i++)
  {
    arr[i] = (char *)malloc(sizeof(char) * n);
    if (!arr[i])
      return (0);
    for (int j = 0; j < n; j++)
      arr[i][j] = ' ';
  }
  star(arr, 0, n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%c", arr[i][j]);
    printf("\n");
  }
  for (int i = 0; i < n; i++)
    free(arr[i]);
  free(arr);
}