//순회강연
#include <stdio.h>
#include <stdlib.h>

int pay[10000][2];
int visit[10001];

int	cmp(const void *a, const void *b)
{
	int *num = (int *)a, *num2 = (int *)b;
	if (*num < *num2)
		return 1;
	else if (num[0] == num2[0])
		if (num[1] < num2[1])
			return 1;
	else if (*num > *num2)
		return -1;
	return 0;
}

int	main()
{
	int i, j, n, ret = 0, tmp = 0;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
		scanf("%d%d",&pay[i][0],&pay[i][1]);
	qsort(pay, n, 8, cmp);
	for (i = 0; i < n; i++)
	{
		for (j = pay[i][1]; j > 0; j--)
		{
			if (visit[j] == 0)
			{
				ret += pay[i][0];
				visit[j] = 1;
				break;
			}
		}
	}
	printf("%d\n",ret);
}