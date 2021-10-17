#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool check[15][15];
int test[15][15][1];
int cnt = 0;
int check2 = 0;

void fn(int n,int su)
{
  if (n == su)
  {
    cnt++;
    return;
  }

  int t;
  for (int j = 0; j < su; j++)
  {
    check2 = 0;
    if (check[n][j])
    {
      
      check2 = 1;
      //세로 제거
      for (int i = n+1; i < su; i++)
      {
        if (check[i][j])
        {
          check[i][j] = 0;
          test[i][j][0] = n;
        }
      }
      //오른쪽 하단 대각선
      int a = 1;
      for (int i = j; i+a < su && n+a < su; a++)
      {
        if (check[n + a][i + a])
        {
          check[n + a][i + a] = 0;
          test[n + a][i + a][0] = n;
        }
      }

      //왼쪽 하단 대각선
      a = 1;
      for (int i = j; i - a > -1 && n + a  < su; a++)
      {
        if (check[n + a][i - a])
        {
          check[n + a][i - a] = 0;
          test[n+a][i-a][0] = n;
        }
      }

      fn(n+1, su);
      for (int i = n +1; i < su; i++)
      {
        if (test[i][j][0] == n)
          check[i][j] = 1;
      }
       a = 1;
       for (int i = j; i + a < su && n + a < su; a++)
       {
         if (test[n + a][i + a][0] == n)
         check[n + a][i + a] = 1;
       }
       a = 1;
       for (int i = j; i - a > -1 && n + a < su; a++)
       {
         if (test[n + a][i - a][0] == n)
           check[n + a][i - a] = 1;
       }
    }
  }
  if (check2 != 1)
    return;
}

int main(void)
{
  int su;
  scanf("%d", &su);
  for (int i = 0; i < su; i++)
  {
    for (int j = 0; j < su; j++)
    {
      check[i][j] = 1;
    }
  }
  fn(0,su);
  printf("%d", cnt);
}