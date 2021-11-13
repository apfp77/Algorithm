#include <stdio.h>

int n, m, v, v1, v2;
int check_arr[1001];
int sq_i;
int queue_arr[1001];
int queue_print[1001];
int print_index;
int d[1001][1001];


void dfs(int cnt)
{
	printf("%d ", cnt);
	for (int i = 1; i <= n; i++)
	{
		if (d[cnt][i] && !check_arr[i])
		{
			check_arr[i] = 1;
			dfs(i);
		}
	}
}

void q_pop()
{
	queue_print[print_index] = queue_arr[0];
	print_index++;
	for (int i = 0; i <= sq_i - 1; i++)
	{
		queue_arr[i] = queue_arr[i + 1];
		queue_arr[i + 1] = 0;
	}
	sq_i--;
}

void bfs()
{
	while (queue_arr[0])
	{
		for (int i = 1; i <= n; i++)
		{
			if (d[queue_arr[0]][i] && !check_arr[i])
			{
				check_arr[i] = 1;
				queue_arr[sq_i] = i;
				sq_i++;
			}
		}
		q_pop();
	}
}

int main(void)
{
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		scanf(" %d %d", &v1, &v2);
		d[v1][v2] = 1;
		d[v2][v1] = 1;
	}
	check_arr[v] = 1;
	dfs(v);
	printf("\n");
	queue_arr[0] = v;
	for (int i = 0; i <= n; i++)
		check_arr[i] = 0;
	check_arr[v] = 1;
	sq_i = 1;
	bfs();

	for (int i = 0; i < n; i++)
	{
		if (queue_print[i])
			printf("%d ", queue_print[i]);
	}
	printf("\n");
}