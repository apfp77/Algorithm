//최소 힙
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

int main()
{
	int n, t, val;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &t);
		if (t == 0)
		{
			if (pop(&val) == 0)
				printf("0\n");
			else
				printf("%d\n", val);
		}
		else
			push(t);
	}
}