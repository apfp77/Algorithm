//유기농 배추

#include <stdio.h>

int m, n, k, t, v1, v2;
int edge[51][51];

void dfs(j, z)
{
	edge[j][z] = 0;

	//상
	if (j + 1 < n)
		if (edge[j + 1][z])
			dfs(j + 1, z);

	//하
	if (j - 1 >= 0)
		if (edge[j-1][z])
			dfs(j - 1, z);
	
	//좌
	if (z - 1 >= 0)
		if (edge[j][z - 1])
			dfs(j, z - 1);

	//우
	if (z + 1 < m)
		if (edge[j][z + 1])
			dfs(j, z + 1);
	

}

int main(void)
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int cnt = 0;
		scanf(" %d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++)
		{
			scanf(" %d %d", &v1, &v2);
			edge[v2][v1] = 1;
		}

		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < m; z++)
			{
				if (edge[j][z])
				{
					dfs(j, z);
					cnt ++;
				}
			}
			
		}
		
		printf("%d\n", cnt);


		for (int j = 0; j < n; j++)
			for (int z = 0; z < m; z++)
				edge[j][z] = 0;
	}
	
}