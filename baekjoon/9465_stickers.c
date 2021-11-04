#include <stdio.h>

int mx(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int d[2][100001];
	int input[2][100001];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &m);
		for (int j = 0; j < 2; j++)
			for (int z = 1; z <= m; z++)
			scanf(" %d", &input[j][z]);

		d[0][0] = d[1][0] = 0;
		d[0][1] = input[0][1];
		d[1][1] = input[1][1];
		for (int j = 2; j <= m; j++)
		{
				d[0][j] = input[0][j] + mx(d[1][j-1], d[1][j-2]);
				d[1][j] = input[1][j] + mx(d[0][j-1], d[0][j-2]);
		}
		printf("%d\n",mx(d[0][m], d[1][m]));
	}
}