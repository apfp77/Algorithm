#include <stdio.h>
#include <stdlib.h>

int	zero_cnt(int **arr)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = -1;
	j = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			if (!arr[i][j])
				cnt++;
	}
	return (cnt);
}

int	check(int w, int h, int val, int **arr)
{
	int	n;
	int	m;
	int	i;
	int	j;

	i = -1;
	j = -1;
	n = w / 3 * 3 + 3;
	m = h / 3 * 3 + 3;
	while (++i < 9)
		if (arr[h][i] == val)
			return (0);
	i = -1;
	while (++i < 9)
		if (arr[i][w] == val)
			return (0);
	i = m - 4;
	while (++i < m)
	{
		j = n - 4;
		while (++j < n)
			if (arr[i][j] == val)
				return (0);
	}
	return (1);
}

void	print(int **arr)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void	calc(int cnt, int n, int h, int **arr)
{
	static int	finish = 0;
	int			i;
	int			j;
	int			z;

	if (finish == 1)
		return ;
	if (cnt == n)
	{
		finish = 1;
		print(arr);
		return ;
	}
	i = h - 1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (!arr[i][j])
			{
				z = 0;
				while (++z < 10)
				{
					if (check(j, i, z, arr))
					{
						arr[i][j] = z;
						calc(cnt + 1, n, i, arr);
						arr[i][j] = 0;
					}
				}
				return ;
			}
		}
	}
}

int	main(void)
{
	int	n;
	int	**arr;
	int	i;
	int	j;

	arr = (int **)malloc(sizeof(int *) * 9);
	if (!arr)
		return (0);
	i = -1;
	while (++i < 9)
	{
		arr[i] = (int *)malloc(sizeof(int) * 9);
		if (!arr)
			return (0);
		j = -1;
		while (++j < 9)
			scanf(" %d", &arr[i][j]);
	}
	n = zero_cnt(arr);
	calc(0, n, 0, arr);
}
