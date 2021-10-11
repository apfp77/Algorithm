#include <stdio.h>

void max(int su, char *input, int *maxprint)
{
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr_index = 9;
  int cnt;
  int j;
  int i;

  i = -1;
  while (++i < su + 1)
  {
    arr_index = 9;
    cnt = 0;
    j = i;
    while (arr[arr_index] == -1)
      arr_index--;
    while (input[j] != '>' && input[j])
    {
      cnt++;
      j++;
    }
    maxprint[i] = arr[arr_index] - cnt;
    arr[maxprint[i]] = -1;
  }
}
void min(int su, char *input, int *minprint)
{
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr_index = 0;
  int cnt;
  int j;
  int i;

  i = -1;
  while (++i < su + 1)
  {
    arr_index = 0;
    cnt = 0;
    j = i;
    while (arr[arr_index] == -1)
      arr_index++;
    while (input[j] == '>' && input[j])
    {
      cnt++;
      j++;
    }
    minprint[i] = arr[arr_index] + cnt;
    arr[minprint[i]] = -1;
  }
}

int main(void)
{
  int su;
  scanf("%d", &su);
  char input[su];
  int i;
  int maxprint[su + 1];
  int minprint[su + 1];

  i = -1;
  while (++i < su)
    scanf("%s", &input[i]);

  max(su, input, maxprint);
  min(su, input, minprint);

  i = -1;
  while (++i < su + 1)
    printf("%d", maxprint[i]);
  printf("\n");
  i = -1;
  while (++i < su + 1)
    printf("%d", minprint[i]);
}