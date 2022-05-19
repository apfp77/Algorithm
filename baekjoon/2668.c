//숫자고르기
#include <stdio.h>
#include <stdlib.h>

int n, su[101], ret[101], ret_size;

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &su[i]);
	for (int i = 1; i <= n; i++)
	{
		int j = su[i];
		int cnt = 0;
		while (cnt <= n)
		{
			if (i == j)
			{
				ret[ret_size++] = i;
				break;
			}
			j = su[j];
			cnt++;
		}
	}
	qsort(ret, ret_size, 4, cmp);
	printf("%d\n",ret_size);
	for (int i = 0; i < ret_size; i++)
	{
		printf("%d\n",ret[i]);
	}
		
}