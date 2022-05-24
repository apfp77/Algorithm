//연료 채우기
#include <stdio.h>
#include <stdlib.h>

int heap[10000], oil[10000][2], heap_size;

void push(int num)
{
	int tmp = heap_size, tmp2;
	heap[tmp] = num;
	while (tmp > 0 && heap[tmp] > heap[(tmp - 1) / 2])
	{
		tmp2 = heap[tmp];
		heap[tmp] = heap[(tmp - 1) / 2];
		heap[(tmp - 1) / 2] = tmp2;
		tmp = (tmp - 1) / 2;
	}
	heap_size++;
}

int pop()
{
	int par, child, tmp, ret = heap[0];
	heap_size--;
	heap[0] = heap[heap_size];
	heap[heap_size] = 0;
	par = 0;
	while (par * 2 + 1 < heap_size)
	{
		if (par * 2 + 2 == heap_size)
			child = par * 2 + 1;
		else
			child = heap[par * 2 + 1] > heap[par * 2 + 2] ? par * 2 + 1 : par * 2 + 2;
		if (heap[par] > heap[child])
			break;
		tmp = heap[par];
		heap[par] = heap[child];
		heap[child] = tmp;
		par = child;
	}
	return (ret);
}

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n, i, now, arrival, ret;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &oil[i][0], &oil[i][1]);
	scanf("%d%d", &arrival, &now);
	qsort(oil, n, 8, cmp);
	ret = 0;
	i = 0;
	while (now < arrival)
	{
		while (i < n && oil[i][0] <= now)
		{
			push(oil[i][1]);
			i++;
		}
		if (heap_size < 1)
		{
			ret = -1;
			break;
		}
		now += pop();
		ret++;
	}
	printf("%d\n", ret);
}