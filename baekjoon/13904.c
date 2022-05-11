//과제
#include <stdio.h>
#include <stdlib.h>

int heap[1000][2];
int ret[1001];

int cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b ? -1 : 1);
}

int	main()
{
	int n, i, j, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d",&heap[i][1], &heap[i][0]);
	qsort(heap, n, 8, cmp);
	for (i = 0; i < n; i++)
	{
		for (j = heap[i][1]; j > 0; j--)
		{
			if (ret[j] == 0)
			{
				ret[j] = 1;
				sum += heap[i][0];
				break;
			}
		}
	}
	printf("%d\n",sum);
}