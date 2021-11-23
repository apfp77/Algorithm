#include <stdio.h>
#include <string.h>
#define MAX 100001
int main(void)
{
	int N, K, num, head = 0, tail = 0, visit[MAX], que[MAX];
	scanf("%d %d", &N, &K);
	memset(visit, -1, MAX * 4);
	visit[N] = 0;
	que[tail++] = N;
	while (head != tail)
	{
		num = que[head++];
		if (num * 2 < MAX && visit[num * 2] == -1)
		{
			visit[num * 2] = visit[num];
			que[tail++] = num * 2;
		}
		if (num - 1 >= 0 && visit[num - 1] == -1)
		{
			visit[num - 1] = visit[num] + 1;
			que[tail++] = num - 1;
		}
		if (num + 1 < MAX && visit[num + 1] == -1)
		{
			visit[num + 1] = visit[num] + 1;
			que[tail++] = num + 1;
		}
	}
	printf("%d\n", visit[K]);
	return 0;
}