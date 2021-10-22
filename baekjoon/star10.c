#include <stdio.h>

void star(int h, int w, int n)
{
  if ((h / n) %3 == 1 && (w / n) % 3 == 1)
    printf(" ");
  else if ((n / 3) == 0)
    printf("*");
  else
    star(h, w, n/3);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int w;
  int h;

  w = -1;
  h = -1;
  while (++h < n)
  {
    w = -1;
    while (++w < n)
      star(h, w, n);
    printf("\n");
  }
}