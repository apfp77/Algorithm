#include <stdio.h>
#include <stdlib.h>

void arr_swap(int *arr, int i, int j)
{
  int temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int main(void)
{
  int i, j, len;
  int *arr;

  i = 0;
  scanf("%d", &len);
  arr = (int *)malloc(sizeof(int) * len);
  if (arr == NULL)
    return (0);
  j = len - 1;
  while (i < len)
  {
    scanf("%d", &arr[i]);
    i++;
  }
  i = len - 1;
  while (i > 0 && arr[i] > arr[i-1])
    i--;
  if (i == 0)
  {
    printf("%d", -1);
    return (0);
  }
  while (arr[i-1] < arr[j])
    j--;
  arr_swap(arr, i - 1, j);
  while (i < len)
  {
    j = i + 1;
    while (j < len)
    {
      if (arr[i] < arr[j])
      {
        arr_swap(arr, i, j);
      }
      j++;
    }
    i++;
  }
  
  i = -1;
  while (++i < len)
    printf("%d ", arr[i]);
  free(arr);
  arr = NULL;
}