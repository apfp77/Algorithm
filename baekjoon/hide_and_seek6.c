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
  int su;
  scanf("%d", &su);
  int bin;
  scanf("%d", &bin);
  int arr[su];
  int i = -1;

  while (++i < su)
  {
    scanf("%d", &arr[i]);
    arr[i] -= bin;
    if (arr[i] < 0)
      arr[i] *= -1;
  }
  if (su == 1)
  {
    printf("%d", arr[0]);
    return (0);
  }
  i = -1;
  while (++i < su -1)
  {
    arr[i+1] = gcd(arr[i], arr[i+1]);
  }
  printf("%d", arr[i]);


}