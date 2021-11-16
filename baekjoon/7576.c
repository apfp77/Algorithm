//토마토
#include <stdio.h>

int n, m;
int edge[1001][1001];
int qu[1000010][3];
int qu_i; //큐 마지막 인덱스
int qu_f; //큐 현재 인덱스

void push(int h, int w, int val)
{
	qu[qu_i][0] = h;
	qu[qu_i][1] = w;
	qu[qu_i][2] = val;
	qu_i++;
}


int	main(void)
{
	scanf("%d %d", &m, &n);
	int mx = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %d", &edge[i][j]);
			if (edge[i][j] == 1)
				push(i, j, 1);
		}
	}

	while (qu_f != qu_i)
	{
		if (qu[qu_f][0] != 0)
			if (edge[qu[qu_f][0] - 1][qu[qu_f][1]] == 0) //상
			{
				edge[qu[qu_f][0] - 1][qu[qu_f][1]] = qu[qu_f][2] + 1;
				push(qu[qu_f][0] - 1, qu[qu_f][1], qu[qu_f][2] + 1);
			}

		if (qu[qu_f][0] < n - 1)
			if (edge[qu[qu_f][0] + 1][qu[qu_f][1]] == 0) //하
			{
				edge[qu[qu_f][0] + 1][qu[qu_f][1]] = qu[qu_f][2] + 1;
				push(qu[qu_f][0] + 1, qu[qu_f][1], qu[qu_f][2] + 1);
			}

		if (qu[qu_f][1] != 0)
			if (edge[qu[qu_f][0]][qu[qu_f][1] - 1] == 0) //좌
			{
				edge[qu[qu_f][0]][qu[qu_f][1] - 1] = qu[qu_f][2] + 1;
				push(qu[qu_f][0], qu[qu_f][1] - 1, qu[qu_f][2] + 1);
			}

		if (qu[qu_f][1] < m - 1)
			if (edge[qu[qu_f][0]][qu[qu_f][1] + 1] == 0) //우
			{
				edge[qu[qu_f][0]][qu[qu_f][1] + 1] = qu[qu_f][2] + 1;
				push(qu[qu_f][0], qu[qu_f][1] + 1, qu[qu_f][2] + 1);
			}
		qu_f++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (edge[i][j] == 0)
			{
				printf("-1\n");
				return (0);
			}
			mx = mx > edge[i][j] ? mx : edge[i][j];
		}
	}
	printf("%d\n", mx - 1);
}
