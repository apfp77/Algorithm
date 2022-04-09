#include <stdio.h>

void quick_sort(int arr[], int left, int right)
{
	int i = left;
	int p = arr[(left + right) / 2];
	int j = right;
	int	tmp;

	while (i <= j)
	{
		while (arr[i] < p)
			i++;
		while (arr[j] > p)
			j--;

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort (arr, left, j);
	if (right > i)
		quick_sort (arr, i, right);	
}

int	main(void)
{
	int arr[] = {8,0,3,2,1,4,5,6,9,7};
	quick_sort(arr,0,9);
	for (int i = 0; i < 10; i++)
		printf("%d\n",arr[i]);
}