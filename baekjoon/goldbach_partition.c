#include <stdio.h>

int sosu(int a)
{
  int i;
  i = 1;
  if (a == 1)
    return (0);
  while (++i < a)
  {
    if (a % i == 0)
      return (0);
    if (i * i > a)
      return (a);
  }
  return (a);
}

int main(void)
{
  int su;
  scanf("%d", &su);
  // 100만까지 소수의 개수
  int prime_numbers[78498];
  int p_i;
  int i;
  int buf;
  int print[su];
  int j;
  int z;
  int a;
  int cnt;

  i = 1;
  p_i = -1;
  while (++i <= 1000000)
  {
    buf = sosu(i);
    if (buf != 0)
      prime_numbers[++p_i] = buf;
  }

  i = -1;
  while (++i < su)
  {
    j = 0;
    scanf("%d", &buf);
    if (buf > 999983)
      j = p_i+1;
    else
    {
      while (prime_numbers[j] < buf)
        j++;
    }
    a = j-1;
    cnt = 0;
    z = 0;
    while (prime_numbers[z] <= buf/2 && z <= a)
    {
      if (prime_numbers[z] + prime_numbers[a] == buf)
      {
        cnt++;
        a--;
      } 
      else if (prime_numbers[z] + prime_numbers[a] > buf)
      {
         a--;
         continue;
      }
      z++;
    }
    print[i] = cnt;
  }
  
  i = -1;
  while (++i < su)
    printf("%d\n", print[i]);

  return (0);
}