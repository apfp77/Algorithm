//빵집
#include <stdio.h>

char road[10001][501];
int r, c;

int dfs(int i, int j)
{
	road[i][j] = 'x';
	if (j == c - 1)
		return (1);

	for (int tmp = -1; tmp < 2 ; tmp++)
	{
		if (i + tmp >= 0 && road[i + tmp][j + 1] == '.')
		{
			if (dfs(i + tmp, j + 1))
				return 1;
		}
	}
	return 0;
}

int	main()
{
	int i, ret = 0;
	scanf("%d %d",&r,&c);
	for (i = 0; i < r; i++)
		scanf("%s",road[i]);
	for (i = 0; i < r; i++)
		ret += dfs(i, 0);
	printf("%d\n",ret);
}
