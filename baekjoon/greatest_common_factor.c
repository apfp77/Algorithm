#include <stdio.h>

int gcd(long long a, long long b)
{
  long long temp;
  if (b > a)
  {
    temp = a;
    a = b;
    b = temp;
  }
  
  if (a % b == 0)
    return b;

  while (b > 0)
  {
    temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

int main(void)
{
  long long a;
  long long b;
  int result  = 0;
  long long i = 1;

  scanf("%lld %lld", &a, &b);
  result = gcd(a, b);
  i = 0;
  while (++i <= result)
    printf("1");
  return (0);
}