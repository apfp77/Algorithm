//수 묶기
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a < *(int *)b);
}

int cmp2(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

int retu(int val[], int n)
{
	int ret = 0;
	for (int i = 0; i < n;)
	{
		if (i + 1 < n)
			ret += ((val[i] + val[i + 1]) > (val[i] * val[i + 1])) ? (val[i] + val[i + 1]) : (val[i] * val[i + 1]);
		i += 2;
	}
	return ret;
}

int	main()
{
	int n, a = 0, b = 0, tmp, tmp2 = 0, arr[50] = {0, }, arr2[50] = {0, };
	long long ret = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&tmp);
		if (tmp > 0)
			arr[a++] = tmp;
		else if (tmp < 0)
			arr2[b++] = tmp;
		else
			tmp2++;
	}
	qsort(arr, a, 4, cmp);
	qsort(arr2, b, 4, cmp2);
	ret += retu(arr, a);
	ret += retu(arr2, b);
	if (a % 2 != 0)
		ret += arr[a - 1];
	if (b % 2 != 0 && tmp2 == 0)
		ret += arr2[b - 1];
	printf("%lld\n",ret);
}