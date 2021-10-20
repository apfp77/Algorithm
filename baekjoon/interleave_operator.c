#include <stdio.h>
#include <stdbool.h>

int m[11];
int max = -1000000000;
int min = 1000000000;

int val(int op, int value, int i)
{
  if (op == 1)
    value += m[i + 1];
  else if (op == 2)
    value -= m[i + 1];
  else if (op == 3)
    value *= m[i + 1];
  else if (op == 4)
    value /= m[i + 1];
  return value;
}

void calc(int k, int *op, bool check[][4], int n)
{
  static int b[11]; 
  static int b_i = 0;
  int value = m[0];
  if (k == n - 1)
  {
    for (int i = 0; i < b_i; i++)
      value = val(b[i], value, i);
    max = value > max ? value : max;
    min = value < min ? value : min;
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    if (check[k][i])
    {
      check[k][i] = 0;
      b[b_i] = i + 1;
      b_i++;
      op[i]--;
      if (!op[i])
      {
        for (int j = k + 1; j < n; j++)
          check[j][i] = 0;
      }
      calc(k + 1, op, check, n);
      b[b_i] = 0;
      b_i--;
      op[i]++;
      for (int j = k + 1; j < n; j++)
        check[j][i] = 1;
      check[k][i] = 1;
    }
  }
}

int main(void)
{
  int n;
  int op[4];
  scanf("%d", &n);
  int i;

  i = -1;
  while (++i < n)
    scanf(" %d", &m[i]);
  i = -1;
  while (++i < 4)
    scanf(" %d", &op[i]);
  bool check[n][4];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < n; j++)
      check[j][i] = 0;

  for (int i = 0; i < 4; i++)
    if (op[i] != 0)
      for (int j = 0; j < n; j++)
        check[j][i] = 1;
  calc(0, op, check, n);
  printf("%d\n%d", max, min);
}