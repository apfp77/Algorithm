#include <stdio.h>
#include <stdlib.h>

void arr_swap(int *arr, int i, int j)
{
  int temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int first_arr_check(int *arr, int input)
{
  int i = 0;
  int size = 0;
  while(i < input)
  {
    if (arr[i] == i+1)
    {
      size++;
    }
    i++;
  }
  if (size == input)
    return (1);
  return (0);
}

int main()
{
  int input, i, j, check;
  int *arr;

  scanf("%d", &input);
  arr = (int *)malloc(sizeof(int) * input);

  i = 0;
  while (i < input)
  {
    scanf("%d", &arr[i]);
    i++;
  }
  if (first_arr_check(arr, input) == 1)
  {
    printf("%d",-1);
    return (0);
  }
  check = input;
  i = input - 1;
  j = i - 1;
  while (i >= 1)
  {
    while (j >= 0)
    { 
      if (arr[i] < arr[j])
      {
        arr_swap(arr, i, j);
        check = j + 1;
        break;
      }
      j--;
    }
    if (check != input)
      break;
    i--;
  }
  while (check <= input - 2)
  {
    i = check + 1;
    while (i <= input -1)
    {
      if (arr[check] < arr[i])
      {
        arr_swap(arr, check, i);
      }
      i++;
    }
    check++;
  }
  
  i = 0;
  while (i < input)
  {
    printf("%d ", arr[i]);
    i++;
  }
  return (0);
}