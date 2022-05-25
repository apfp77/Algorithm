// PPAP
#include <stdio.h>

char s[1000000];

int main()
{
	scanf("%s", s);
	int i, cnt;
	for (i = cnt = 0; s[i]; i++)
	{
		if (s[i] == 'P')
		{
			cnt++;
			continue;
		}
		if (s[i] == 'A' && cnt >= 2 && s[i + 1] == 'P')
		{
			cnt--;
			i++;
		}
		else
		{
			printf("NP");
			return 0;
		}
	}
	printf(cnt != 1 ? "NP" : "PPAP");
	return 0;
}