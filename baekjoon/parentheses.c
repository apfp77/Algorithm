#include <stdio.h>

int main(void)
{
  int su;
  int i;
  int j;
  int buf;

  i = -1;
  scanf("%d", &su);
  char arr[su][52];

  while (++i < su)
  {
    scanf("%s", arr[i]);
  }

  i = -1;
  while (++i<su)
  {
    j = -1;
    buf = 0;
    while (arr[i][++j])
    {
      if (arr[i][j] == '(')
        buf += 1;
      else
        buf -= 1;
      if (buf < 0)
        break;
    }
    if (buf == 0)
      printf("%s\n", "YES");
    else
      printf("%s\n","NO");
  }
}