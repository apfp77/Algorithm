//바이러스
#include <stdio.h>

int n, m, e1, e2;
int check[101];
int edge[101][101];
int cnt;

void dfs(int ind)
{
	// printf("%d ", ind);
	for (int i = 1; i <= n; i++)
	{
		if (edge[ind][i] && !check[i])
		{
			check[i] = 1;
			cnt++;
			dfs(i);
		}
	}
}

int	main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf(" %d %d", &e1, &e2);
		edge[e1][e2] = 1;
		edge[e2][e1] = 1;
	}
	check[1] = 1;
	dfs(1);
	printf("%d\n", cnt);
}