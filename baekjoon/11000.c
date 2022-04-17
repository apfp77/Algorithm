//강의실 배정
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200000

int heap[MAX_SIZE];
int heap_size = 0;
int arr[200000][2];

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int left, int right)
{
	int i = left, j = right, p = arr[(left + right) / 2][0];

	while (i <= j)
	{
		while (arr[i][0] < p) i++;
		while (arr[j][0] > p) j--;
		if (i <= j)
		{
			swap(&arr[i][0], &arr[j][0]);
			swap(&arr[i][1], &arr[j][1]);
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(left, j);
	if (right > i)
		quick_sort(i, right);
}

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

int pop()
{
	int tmp = 0, child = 0, node = 0;
	if (heap_size <= 0)
		return (0);
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

int main(void)
{
	int n, ret = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &arr[i][0], &arr[i][1]);
	quick_sort(0, n-1);
	push (arr[0][1]);
	for (int i = 1; i < n; i++)
	{
		if (heap_size > 0)
		{
			if (arr[i][0] >= heap[0])
				pop();
			else
				ret++;
			push (arr[i][1]);
		}
	}
	printf("%d\n",ret);
}