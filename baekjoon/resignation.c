#include <stdio.h>

int n;
int arr[15][2];
int mx = 0;

void calc(int k, int buf)
{
  mx = mx < buf ? buf : mx;

  for (int i = k; i < n; i++)
  {
    if ((i + arr[i][0]) > n)
      continue;
    calc(i + arr[i][0], buf + arr[i][1]);
  }
}

int main(void)
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf(" %d %d", &arr[i][0], &arr[i][1]);

  for (int i = 0; i < n; i++)
  {
    if (i + arr[i][0] <= n)
      calc(i + arr[i][0], arr[i][1]);
  }
  printf("%d\n", mx);
}