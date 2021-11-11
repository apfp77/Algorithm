#include <stdio.h>

int d[1001][1001];
int n, m, v1, v2;
int check_arr[1001];
int sq_i;

void dfs(int cnt)
{
	// printf("%d", cnt);
	for (int i = 1; i <= n; i++)
	{
		if (d[cnt][i] && !check_arr[i])
		{
			check_arr[i] = 1;
			dfs(i);
		}
	}
}

int	main(void)
{
	scanf("%d %d", &n, &m);
	int test = 0;
	for (int i = 0; i < m; i++)
	{
		scanf(" %d %d", &v1, &v2);
		d[v1][v2] = 1;
		d[v2][v1] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check_arr[i])
		{
			dfs(i);
			test++;
		}
	}
	printf("%d\n",test);

}