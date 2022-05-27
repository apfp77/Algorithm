//택배
#include <stdio.h>
#include <stdlib.h>

int arr[10001][3];
int box[2001];

int cmp(const void *a, const void *b)
{
	return (((int *)a)[1] - ((int *)b)[1]);
}

int main()
{
	int N, M, MAX, ret = 0;
	scanf("%d%d%d", &N, &MAX, &M);
	for (int i = 0; i < M; i++)
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	qsort(arr, M, 12, cmp);

	for (int i = 0; i < M; i++)
	{
		int mx = 0;
		int val = 0;
		for (int j = arr[i][0]; j < arr[i][1]; j++)
			mx = mx > box[j] ? mx : box[j];
		val = arr[i][2] < MAX - mx ? arr[i][2] : MAX - mx;
		for (int j = arr[i][0]; j < arr[i][1]; j++)
			box[j] += val;
		ret += val;
	}
	printf("%d\n", ret);
}
