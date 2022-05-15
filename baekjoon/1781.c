//컵라면
#include <stdio.h>
#include <stdlib.h>

int arr[200000][2];
int pq_size;
int pq[200000];

int	cmp(const void *a, const void *b)
{
	int *num = (int *)a;
	int *num2 = (int *)b;
	if (*num > *num2)
		return 1;
	if (*num == *num2)
		if (num[1] < num2[1])
			return 1;
	if (*num < *num2)
		return -1;
	return 0;
}

void push(int num)
{	
	int tmp = pq_size, tmp2;
	pq[tmp] = num;
	while (tmp > 0 && pq[tmp] < pq[(tmp - 1)/2])
	{
		tmp2 = pq[tmp];
		pq[tmp] = pq[(tmp - 1) / 2];
		pq[(tmp - 1) / 2] = tmp2; 
		tmp = (tmp - 1) / 2;
	}
	pq_size++;
}

void pop()
{
	if (pq_size < 1)
		return ;
	int tmp = --pq_size, child, tmp3;
	pq[0] = pq[tmp];
	pq[tmp] = 0;
	tmp = 0;
	while (tmp * 2 + 1 < pq_size)
	{
		if (tmp * 2 + 2 == pq_size)
			child = tmp *2 + 1;
		else
			child = pq[tmp * 2 + 1] > pq[tmp * 2 + 2] ? tmp * 2 + 2 : tmp * 2 + 1;
		if (pq[tmp] < pq[child])
			break;
		tmp3 = pq[tmp];
		pq[tmp] = pq[child];
		pq[child] = tmp3;
		tmp = child;
	}
}

int main()
{
	int n, i, j, k = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &arr[i][0], &arr[i][1]);
	qsort(arr, n, 8, cmp);
	for (i = 0; i < n; i++)
	{
		if (arr[i][0] == pq_size && arr[i][1] > pq[0])
			pop();
		if (arr[i][0] > pq_size)
			push(arr[i][1]);
	}
	
	for (i = 0; i < pq_size; i++)
		k += pq[i];
	printf("%d\n",k);
}