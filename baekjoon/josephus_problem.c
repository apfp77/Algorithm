#include<stdio.h>
#include <stdlib.h>

void ft_swap(int *arr, int index, int total)
{
  while (index < total)
  {
    arr[index] = arr[index+1];
    index++;
  }
}

int main(void)
{
  int jump;
  int size;
  int total;
  scanf("%d %d", &size, &jump);
  int *arr = (int *)malloc(sizeof(int)*size);
  int *print = (int *)malloc(sizeof(int)*size);
  int index = 0;
  int print_index = 0;

  total = -1;
  while (++total < size)
    arr[total] = total + 1;
  while (total > 0)
  {
    index += jump - 1;
    while (index >= total)
      index -= total;
    print[print_index] = arr[index];
    ft_swap(arr, index, total);
    print_index++;
    total--;
  }
  total = -1;
  printf("<");
  while (++total < size)
  {
    printf("%d", print[total]);
    if (total == size -1)
      break;
    else
      printf(", ");
      
  }
  printf(">");
  return (0);
}