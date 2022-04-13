//카드 정렬하기
#include <stdio.h>

#define MAX_SIZE 100001

int heap[MAX_SIZE];
int heap_size = 0;

int push(int value)
{
	int tmp = heap_size, buf = 0;

	if (heap_size + 1 > MAX_SIZE)
		return (0);
	heap[heap_size] = value;
	while (tmp > 0 && heap[tmp] < heap[(tmp - 1) / 2])
	{
		buf = heap[tmp];
		heap[tmp] = heap[(tmp - 1) / 2];
		heap[(tmp - 1) / 2] = buf;
		tmp = (tmp - 1) / 2;
	}
	heap_size += 1;
	return (1);
}

int pop(int *val)
{
	int tmp = 0, child = 0, node = 0;
	if (heap_size <= 0)
		return (0);
	*val = heap[0];
	heap_size--;
	heap[0] = heap[heap_size];
	heap[heap_size] = 0;
	while (node * 2 + 1 < heap_size)
	{
		if (node * 2 + 2 == heap_size)
			child = node * 2 + 1;
		else
			child = heap[node * 2 + 1] < heap[node * 2 + 2] ? node * 2 + 1 : node * 2 + 2;
		if (heap[node] < heap[child])
			break;

		tmp = heap[child];
		heap[child] = heap[node];
		heap[node] = tmp;
		node = child;
	}
	return (1);
}

int	empty()
{
	if (heap_size <= 0)
		return (0);
	return (1);
}

int main()
{
	int n, t, tmp = 0, tmp2 = 0, ret = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&t);
		push(t);
	}
	while (heap_size > 1)
	{
		pop(&tmp);
		pop(&tmp2);
		ret += tmp + tmp2;
		if (!empty())
			break;
		push(tmp + tmp2);
	}
	printf("%d\n",ret);
}