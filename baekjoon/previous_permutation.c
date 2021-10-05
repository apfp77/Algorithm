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

/*
시도 항목

1. 제일 뒤에있는 수를 기준으로 반복문을 돌려서 큰값이 나오면 위치를 바꾸고 내림차순 정렬
 -- 제일 뒤에있는 값이 제일 작은 값이면 -1 해서 다시 반복
==> 기준점이 잘못된 방법이였다, 맨뒤부터 현재값보다 큰 값이 바로 앞에 있다면으로 기준을 바꿧다
*/
