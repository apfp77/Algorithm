//꿀 따기
#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int arr[100000];

int main()
{
	int n, total, tmp, ret;
	total = tmp = ret = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		total += arr[i];
	}
	//벌이 맨 왼쪽과 가운데일때
	tmp = arr[n - 1];
	for (int i = n - 2; i > 0; i--)
	{
		ret = MAX(ret, total - arr[0] - arr[i] + tmp);
		tmp += arr[i];
	}

	//벌이 맨 오른쪽과 가운데일때
	tmp = arr[0];
	for (int i = 1; i < n - 1; i++)
	{
		ret = MAX(ret, total - arr[n - 1] - arr[i] + tmp);
		tmp += arr[i];
	}
	//벌이 양 사이드일때
	for (int i = 1; i < n - 1; i++)
	{
		tmp = arr[i];
		ret = MAX(ret, total - arr[0] - arr[n - 1] + tmp);
	}
	printf("%d\n", ret);
}