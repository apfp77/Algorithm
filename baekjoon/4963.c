//섬의 개수
#include <stdio.h>

int w, h;
int edge[50][50];
int check[50][50];
int cnt;

void dfs(int h_dfs, int w_dfs)
{
	if (w_dfs < w && h_dfs < h && w_dfs > -1 && h_dfs > -1)
	{
		if (edge[h_dfs][w_dfs] && !check[h_dfs][w_dfs])
		{
			check[h_dfs][w_dfs] = 1;
			dfs(h_dfs, w_dfs + 1);		 //우
			dfs(h_dfs, w_dfs - 1);		 //좌
			dfs(h_dfs + 1, w_dfs);		 //하
			dfs(h_dfs + 1, w_dfs + 1); //하 우
			dfs(h_dfs + 1, w_dfs - 1); //하 좌
			dfs(h_dfs - 1, w_dfs); //상
			dfs(h_dfs - 1, w_dfs - 1); //상 좌
			dfs(h_dfs - 1, w_dfs + 1); //상 우
			}
		}
}

int main(void)
{
	while (1)
	{
		cnt = 0;
		scanf("%d %d", &w, &h);
		if (w < 1 || h < 1)
			return 0;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf(" %d", &edge[i][j]);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (edge[i][j] && !check[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				{
					check[i][j] = 0;
					edge[i][j] = 0;
				}
		printf("%d\n",cnt);
	}	
}