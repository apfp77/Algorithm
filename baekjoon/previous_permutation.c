#include <stdio.h>
#include <stdlib.h>


//동적할당 및 입력
void arr_input(int *arr, int input)
{
 
}

void arr_swap(int *arr, int i, int j)
{
  int temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
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
  // i = check + 1;
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
  printf("\n");
}