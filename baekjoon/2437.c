//저울
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

int	main()
{
	int n, ret = 1000002, tmp = 1, arr[1001];
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	qsort(arr, n, 4, cmp);

	for (int i = 0; i < n; i++)
	{
		if (tmp < arr[i])
			break;
		tmp += arr[i];
	}
	printf("%d\n",tmp);
}
