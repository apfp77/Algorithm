//강의실
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

int heap[MAX_SIZE], arr[MAX_SIZE][2], heap_size;

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

void pop()
{
	int tmp = 0, child = 0, node = 0;
	if (heap_size <= 0)
		return;
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
}

int cmp(const void *a, const void *b)
{
	int *num = (int *)a;
	int *num2 = (int *)b;
	if (*num > *num2)
		return 1;
	if (*num == *num2)
		return (num[1] - num2[1]);
	if (*num < *num2)
		return -1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0, tmp = 0; i < n; i++)
		scanf("%d%d%d", &tmp, &arr[i][0], &arr[i][1]);
	qsort(arr, n, 8, cmp);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (heap_size > 0 && arr[i][0] >= heap[0])
			pop();
		else
			cnt++;
		push(arr[i][1]);
	}
	printf("%d\n", cnt);
}