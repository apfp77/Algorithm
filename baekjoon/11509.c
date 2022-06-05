//풍선 맞추기
#include <stdio.h>

int arr[1000001];

int main()
{
	int N, cnt = 0, tmp;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &tmp);
		arr[tmp] > 0 ? arr[tmp]-- : cnt++;
		arr[tmp - 1]++;
	}
	printf("%d\n", cnt);
}