#include <stdio.h>
#include <stdbool.h>

int arr[9][9];
int finish = 0;

//종료조건으로 0의 갯수 세기
int zero_cnt()
{
  int cnt = 0;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (!arr[i][j])
        cnt++;
  return cnt;
}

//가로, 세로, 3x3안에 값이 있는지 체크
bool check(int w, int h, int val)
{
  int n = w / 3 * 3 + 3; // 가로 3 * 3
  int m = h / 3 * 3 + 3; // 세로 3 * 3

  //가로 체크
  for (int i = 0; i < 9; i++)
    if (arr[h][i] == val)
      return false;

  //세로 체크
  for (int i = 0; i < 9; i++)
    if (arr[i][w] == val)
      return false;

  //3 x 3 체크
  for (int i = m - 3; i < m; i++)
    for (int j = n - 3; j < n; j++)
      if (arr[i][j] == val)
        return false;

  return true;
}

//계산 로직
void calc(int cnt, int n, int h)
{
  if (finish == 1)
    return;
  // cnt가 n과 같다면 맨 마지막까지 왔다는 의미
  if (cnt == n)
  {
    finish = 1;
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
        printf("%d ", arr[i][j]);
      printf("\n");
    }
    return;
  }

  //0인 부분을 찾고 체크함수로 돌리면서 값을 넣으면서 재귀
  for (int i = h; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (!arr[i][j])
      {
        int z = 1;
        for (; z < 10; z++)
        {
          if (check(j, i, z))
          {
            arr[i][j] = z;
            calc(cnt + 1, n, i);
            arr[i][j] = 0;
          }
        }
        return;
      }
}

int main(void)
{
  int n;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      scanf(" %d", &arr[i][j]);
  n = zero_cnt();
  calc(0, n, 0);
}