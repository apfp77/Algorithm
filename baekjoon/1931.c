#include <stdio.h>

int n;
int arr[100000][2];

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int left, int right)
{
	int i = left, j = right, p = arr[(left + right) /2][1];

	while (i <= j)
	{
		while (arr[i][1] < p) i++;
		while (arr[j][1] > p) j--;
		if (i <= j)
		{
			swap(&arr[i][1], &arr[j][1]);
			swap(&arr[i][0], &arr[j][0]);
			i++;
			j--;
		}
	}
	if (left < j)	quick_sort(left, j);
	if (right > i) quick_sort(i, right);
}

int main(void)
{
	int ret = 0;
	int tmp = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	quick_sort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		if (arr[i][1] == arr[i + 1][1] && arr[i][0] > arr[i + 1][0])
			swap(&arr[i][0], &arr[i + 1][0]);
	}
	tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i][0] >= tmp)
		{
			ret++;
			tmp = arr[i][1];
		}
	}
	
	printf("%d\n", ret);
	return (0);
}