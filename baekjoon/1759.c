//암호만들기
#include <stdio.h>
#include <stdlib.h>

int mo, ja, m, n;
char arr[15], visit[26];

int cmp(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

int check_alpha(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return (1);
	return (2);
}

void dfs(int index, int cnt)
{
	if (cnt == n)
	{
		if (ja < 2 || mo < 1)
			return;
		for (int i = 0; i < 26; i++)
			if (visit[i] == 1)
				printf("%c", i + 'a');
		printf("\n");
		return;
	}
	for (int i = index + 1; i < m; i++)
	{
		visit[arr[i] - 'a'] = 1;
		check_alpha(arr[i]) == 1 ? mo++ : ja++;
		dfs(i, cnt + 1);
		check_alpha(arr[i]) == 1 ? mo-- : ja--;
		visit[arr[i] - 'a'] = 0;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf(" %c", &arr[i]);
	qsort(arr, m, sizeof(char), cmp);
	for (int i = 0; i <= m - n; i++)
	{
		visit[arr[i] - 'a'] = 1;
		check_alpha(arr[i]) == 1 ? mo++ : ja++;
		dfs(i, 1);
		check_alpha(arr[i]) == 1 ? mo-- : ja--;
		visit[arr[i] - 'a'] = 0;
	}
}