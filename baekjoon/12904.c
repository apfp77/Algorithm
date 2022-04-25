//A와 B
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1001

char s[MAX_SIZE], t[MAX_SIZE];

int	main()
{
	scanf("%s\n",s);
	scanf("%s",t);
	int t_size = strlen(t);
	int s_size = strlen(s);
	int tmp;
	char tmp2;
	while (s_size < t_size)
	{
		tmp = t_size - 1;
		if (t[tmp] == 'A')
			t[tmp] = '\0';
		else
		{
			t[tmp--] = '\0';
			for (int i = 0; i < tmp; i++, tmp--)
			{
				tmp2 = t[tmp];
				t[tmp] = t[i];
				t[i] = tmp2;
			}
		}
		t_size--;
	}
	tmp = 0;
	for (int i = 0; i < s_size; i++)
	{
		if (t[i] != s[i])
			tmp = 1;
	}
	tmp ==  1 ? printf("0\n") : printf("1\n");
}