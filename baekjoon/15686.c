#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647

typedef struct s_map
{
	int x, y;
} map;

int n, m, c_size, h_size, mn = INT_MAX, combi_size, check[13];
map c[13], h[100], combi[13];

void dfs(int index, int cnt)
{
	if (cnt == m)
	{
		int sum = 0;
		for (int i = 0; i < h_size; i++)
		{
			int house_min = INT_MAX;
			for (int j = 0; j < combi_size; j++)
			{
				int tmp = abs(h[i].x - combi[j].x) + abs(h[i].y - combi[j].y);
				house_min = house_min > tmp ? tmp : house_min;
			}
			sum += house_min;
		}
		mn = mn > sum ? sum : mn;
		return;
	}

	for (int i = index; i < c_size; i++)
	{
		if (check[i] == 0)
		{
			combi[combi_size].x = c[i].x;
			combi[combi_size].y = c[i].y;
			combi_size++;
			check[i] = 1;
			dfs(i + 1, cnt + 1);
			check[i] = 0;
			combi_size--;
		}
	}
}

int main(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1)
			{
				h[h_size].x = j;
				h[h_size].y = i;
				h_size++;
			}
			else if (tmp == 2)
			{
				c[c_size].x = j;
				c[c_size].y = i;
				c_size++;
			}
		}
	}
	dfs(0, 0);
	printf("%d\n", mn);
}