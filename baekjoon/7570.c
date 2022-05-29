//줄 세우기
#include <stdio.h>

int arr[1000001];

int main()
{
	int n, tmp, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		arr[tmp] = arr[tmp - 1] > 0 ? arr[tmp - 1] + 1 : 1;
		max = max > arr[tmp] ? max : arr[tmp];
	}
	printf("%d\n", n - max);
}
