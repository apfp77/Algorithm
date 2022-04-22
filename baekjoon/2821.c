//크게 만들기
#include <stdio.h>
#define SIZE 500001
int	main()
{
	int n, k, stack_size = 0, i = 0;
	char s[SIZE] = {0, },stack[SIZE] = {0, };
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	while (s[i])
	{
		while (k > 0 && stack_size > 0 && s[i] > stack[stack_size - 1])
		{
			stack_size--;
			k--;
		}
		stack[stack_size++] = s[i];
		i++;
	}
	while (k > 0)
	{
		stack_size--;
		k--;
	}
	stack[stack_size] = '\0';
	printf("%s\n",stack);
}