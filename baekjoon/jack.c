#include <stdio.h>

int main(void)
{
  int n;
  int max;
  scanf("%d %d", &n, &max);
  int i;
  int j;
  int f;
  int card[n];
  i = -1;
  while (++i < n)
    scanf(" %d", &card[i]);
  int buf;
  int buf2;
  buf = 0;
  buf2 = 0;
  i = -1;
  while (++i < n)
  {
    j = i;
    while (++j < n)
    {
      f = j;
      while (++f < n)
      {
        buf2 = card[i] + card[f] + card[j];
        if (buf2 <= max && buf2 > buf)
          buf = buf2;
      }
    }
  }
  printf("%d", buf);
}