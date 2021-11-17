//나이트의 이동
#include <stdio.h>

int n, t, v1, v2, f1, f2;
int check[301][301];
int que[90010][3];
int q_i;
int q_f;

void push(int i, int j, int z)
{
	que[q_i][0] = i;
	que[q_i][1] = j;
	que[q_i][2] = z;
	q_i++;
}

int main(void)
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		q_i = 0;
		q_f = 0;
		scanf(" %d", &n);
		int edge[n][n];
		scanf(" %d %d",&v1, &v2);
		scanf(" %d %d",&f1, &f2);

		//세로 , 가로순
		que[q_i][0] = v1;
		que[q_i][1] = v2;
		que[q_i][2] = 0;
		q_i++;
		
		while (1)
		{
			if (que[q_f][0] == f1 && que[q_f][1] == f2)
				break;
			
			//좌상
			if (que[q_f][0] > 1 && que[q_f][1] > 0)
				if (!check[que[q_f][0] - 2][que[q_f][1] - 1])
				{
					push(que[q_f][0] - 2, que[q_f][1] - 1, que[q_f][2] + 1);
					check[que[q_f][0] - 2][que[q_f][1] - 1] = 1;
				}


			if (que[q_f][0] > 0 && que[q_f][1] > 1)
				if (!check[que[q_f][0] - 1][que[q_f][1] - 2])
				{
					push(que[q_f][0] - 1, que[q_f][1] - 2, que[q_f][2] + 1);
					check[que[q_f][0] - 1][que[q_f][1] - 2] = 1;
				}
			
			//우상 
			if (que[q_f][0] > 1 && que[q_f][1] + 1 < n)
				if (!check[que[q_f][0] - 2][que[q_f][1] + 1])
				{
					push(que[q_f][0] - 2, que[q_f][1] + 1, que[q_f][2] + 1);
					check[que[q_f][0] - 2][que[q_f][1] + 1] = 1;
				}
				


			if (que[q_f][0] > 0 && que[q_f][1] + 2 < n)
				if (!check[que[q_f][0] - 1][que[q_f][1] + 2])
				{
					check[que[q_f][0] - 1][que[q_f][1] + 2] = 1;
					push(que[q_f][0] - 1, que[q_f][1] + 2, que[q_f][2] + 1);
				}

			//좌하
			if (que[q_f][0] + 2 < n && que[q_f][1] > 0)
				if (!check[que[q_f][0] + 2][que[q_f][1] - 1])
				{
					check[que[q_f][0] + 2][que[q_f][1] - 1] = 1;
					push(que[q_f][0] + 2, que[q_f][1] - 1, que[q_f][2] + 1);
				}

			if (que[q_f][0] + 1 < n && que[q_f][1] > 1)
				if (!check[que[q_f][0] + 1][que[q_f][1] - 2])
				{
					check[que[q_f][0] + 1][que[q_f][1] - 2] = 1;
					push(que[q_f][0] + 1, que[q_f][1] - 2, que[q_f][2] + 1);
				}



			//우하
			if (que[q_f][0] + 2 < n && que[q_f][1] + 1 < n)
				if (!check[que[q_f][0] + 2][que[q_f][1] + 1])
				{
					check[que[q_f][0] + 2][que[q_f][1] + 1] = 1;
					push(que[q_f][0] + 2, que[q_f][1] + 1, que[q_f][2] + 1);
				}

			if (que[q_f][0] + 1 < n && que[q_f][1] + 2 < n)
				if (!check[que[q_f][0] + 1][que[q_f][1] + 2])
				{
					check[que[q_f][0] + 1][que[q_f][1] + 2] = 1;
					push(que[q_f][0] + 1, que[q_f][1] + 2, que[q_f][2] + 1);
				}
			q_f++;
		}
		for (int j = 0; j < 301; j++)
				for (int z = 0; z < 301; z++)
					check[j][z] = 0;
		
		printf("%d\n", que[q_f][2]);
	}
}