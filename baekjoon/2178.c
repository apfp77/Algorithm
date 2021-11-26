#include <stdio.h>
#include <stdbool.h>

int arr[101][101];
int q[10000][3];
bool check[101][101];

int	main(void)
{
	int n, m;
	int q_r, q_f;
	q_r = q_f = 0;
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);

	arr[0][0] = 1;
	q[0][0] = 0;
	q[0][1] = 0;
	q[0][2] = 1;
	q_r++;
	check[0][0] = 1;

	while (q_r != q_f)
	{
		if (q[q_f][0] == n-1 && q[q_f][1] == m-1)
		{
			printf("%d\n", q[q_f][2]);
			break;
		}
		//좌
		if (q[q_f][1] - 1 > -1 && !check[q[q_f][0]][q[q_f][1] - 1] && arr[q[q_f][0]][q[q_f][1] - 1])
		{
			q[q_r][0] = q[q_f][0];
			q[q_r][1] = q[q_f][1] - 1;
			q[q_r][2] = q[q_f][2] + 1;
			q_r++;
			check[q[q_f][0]][q[q_f][1] - 1] = 1;
		}
		//우
		if (q[q_f][1] + 1< m && !check[q[q_f][0]][q[q_f][1] + 1] && arr[q[q_f][0]][q[q_f][1] + 1])
		{
			q[q_r][0] = q[q_f][0];
			q[q_r][1] = q[q_f][1] + 1;
			q[q_r][2] = q[q_f][2] + 1;
			q_r++;
			check[q[q_f][0]][q[q_f][1] + 1] = 1;
		}

		//상
		if (q[q_f][0] - 1 > -1 && !check[q[q_f][0] - 1][q[q_f][1]] && arr[q[q_f][0] - 1][q[q_f][1]])
		{
			q[q_r][0] = q[q_f][0] - 1;
			q[q_r][1] = q[q_f][1];
			q[q_r][2] = q[q_f][2] + 1;
			q_r++;
			check[q[q_f][0] - 1][q[q_f][1]] = 1;
		}
		//하
		if (q[q_f][0] + 1 < n && !check[q[q_f][0] + 1][q[q_f][1]] && arr[q[q_f][0] + 1][q[q_f][1]])
		{
			q[q_r][0] = q[q_f][0] + 1;
			q[q_r][1] = q[q_f][1];
			q[q_r][2] = q[q_f][2] + 1;
			q_r++;
			check[q[q_f][0] + 1][q[q_f][1]] = 1;
		}
		q_f++;
	}

}