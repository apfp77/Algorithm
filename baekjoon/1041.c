//주사위
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a < *(int *)b ? -1 : 1);
}

int	main()
{
	long long n, arr[6], one, two, three, ret = 0;
	scanf("%lld",&n);
	for (int i = 0; i < 6; i++)
		scanf("%lld",&arr[i]);
	if (n > 1)
	{
		arr[0] = arr[0] > arr[5] ? arr[5] : arr[0];
		arr[1] = arr[1] > arr[4] ? arr[4] : arr[1];
		arr[2] = arr[2] > arr[3] ? arr[3] : arr[2];
		qsort(arr, 3, sizeof(long long), cmp);
		one = (n - 1) * (n - 2) * 4 + (n - 2) * (n - 2);
		two = 4 * (n - 1) + 4 * (n - 2);
		three = 4;
		ret = (one + two + three) * arr[0];
		ret = ret + (two + three) * arr[1];
		ret = ret + 4 * arr[2];
	}
	else
	{
		qsort(arr, 6, sizeof(long long), cmp);
		for (int i = 0; i < 5; i++)
			ret += arr[i];
	}
	printf("%lld\n",ret);
}