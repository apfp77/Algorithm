#include <stdio.h>

int n;

int	main(void)
{
	scanf("%d",&n);
	int arr[n];
	int print[n];
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			print[i] = arr[i];
		else
			print[i] = print[i-1] + arr[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret += print[i];
	printf("%d\n",ret);
}