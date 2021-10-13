#include <stdio.h>

int cnt = 0;

int hanoi_cnt(int n)
{
  int i;
  int result;

  i = -1;
  result = 1;
  while (++i < n)
    result <<= 1;
  return result - 1;
}

void hanoi(int n, int start, int middle, int end)
{
  if (n == 0)
    return;
  hanoi(n - 1, start, end, middle);
  printf("%d %d\n", start, end);
  hanoi(n - 1, middle, start, end);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  hanoi_cnt(n);
  printf("%d\n", cnt);
  hanoi(n, 1, 2, 3);
}