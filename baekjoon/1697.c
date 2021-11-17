//숨바꼭질
#include <stdio.h>

//0은 자릿수, 1은 큐의 돌아가는 횟수
int que[100100][2];
int n, k;
int q_i;
int q_f;
int check[100100];

void push(int i, int j)
{
	que[q_i][0] = i;
	que[q_i][1] = j;
	q_i++;
}

int main(void)
{
	scanf("%d %d", &n, &k);
	
	que[0][0] = n;
	que[0][1] = 0;
	q_i++;
	while (q_i != q_f)
	{
		if (que[q_f][0] == k)
			break;

		if (que[q_f][0] + 1 <= k)
		{
			if (!check[que[q_f][0] + 1])
			{
				push(que[q_f][0] + 1, que[q_f][1] + 1);
				check[que[q_f][0] + 1] = 1;
			}
		}
		
			if (!check[que[q_f][0] - 1])
			{
				push(que[q_f][0] - 1, que[q_f][1] + 1);
				check[que[q_f][0] - 1] = 1;
			}

		if (que[q_f][0] * 2 <= 100000)
		{
			if (!check[que[q_f][0] * 2])
			{
				push(que[q_f][0] * 2, que[q_f][1] + 1);
				check[que[q_f][0] * 2] = 1;
			}
		}
		q_f++;
	}
	printf("%d\n", que[q_f][1]);
}
