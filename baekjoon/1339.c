//단어 수학
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[26];

void pasing(char *s)
{
	int n = strlen(s), tmp = 1;
	for (int i = 0; i < n - 1; i++)
		tmp *= 10;
	for (int i = 0; i < n; i++)
	{
		arr[s[i]-'A'] += tmp;
		tmp /= 10;
	}
}

int cmp(const void *a, const void *b)
{
	return (*(int *)a < *(int *)b);
}

int	main()
{
	int n, ret = 0;
	char s[10] ={0,};
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s",s);
		pasing(s);
	}
	qsort(arr, 26, 4, cmp);
	
	int j = 9;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != 0)
		{
			arr[i] *= j;
			j--;
		}
	}
	for (int i = 0; i < 26; i++)
		ret += arr[i];
	printf("%d\n",ret);
}