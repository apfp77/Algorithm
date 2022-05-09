//행복유치원
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a < *(int *)b ? -1 : 1);
}

int s[300001];

int main()
{
	int n, k, i, ret = 0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);
	for (i = 0; i < n - 1; i++)
		s[i] = abs(s[i] - s[i + 1]);
	qsort(s, n - 1, 4, cmp);
	for (i = 0; i < n - k; i++)
		ret += s[i];
	printf("%d\n", ret);
}