#include <stdio.h>

typedef struct s_stack
{
	char character;
	int value;
}	t_stack;


int	main(void)
{
	char input[101];
	scanf("%s",input);
	t_stack stack[101];
	int stack_index;
	int i;
	int j;
	int cnt;

	i = -1;
	while (++i < 101)
		stack[i].value = 0;

	i = -1;
	stack_index = 0;
	cnt = 0;
	while (input[++i])
	{
		//우선 값 넣기
		if (input[i] == '(' || input[i] == ')')
		{
			stack[stack_index].character = input[i];
			stack[stack_index].value = 1;
		}
		else if (input[i] == '*' || input[i] == '/')
		{
			stack[stack_index].character = input[i];
			stack[stack_index].value = 2;
		}
		else if (input[i] == '+' || input[i] == '-')
		{
			stack[stack_index].character = input[i];
			stack[stack_index].value = 3;
		}
		else
		{
			printf("%c", input[i]);
			continue;
		}

		if ((input[i] == '(' || input[i] == ')') || cnt > 0)
		{
			if (input[i] == '(')
				cnt++;
			
			else if (input[i] == ')')
			{
				while (stack[stack_index].character != '(')
				{
					if (stack[stack_index].character != ')')
						printf("%c", stack[stack_index].character);
					stack_index--;
				}
				stack_index--;
				cnt--;
			}
			else
			{
				j = stack_index - 1;
				while (stack_index > 0 && stack[stack_index].value >= stack[j].value && stack[j].character != '(')
				{
					printf("%c", stack[j].character);
					stack[j].character = stack[stack_index].character;
					stack[j].value = stack[stack_index].value;
					stack_index--;
					j--;
				}
			}
		}
		else
		{
			j = stack_index-1;
			while (stack_index > 0 && stack[stack_index].value >= stack[j].value)
			{
				printf("%c", stack[j].character);
				stack[j].character = stack[stack_index].character;
				stack[j].value = stack[stack_index].value;
				stack_index--;
				j--;
			}
		}
		stack_index++;
	}
	while (--stack_index != -1)
	{
			printf("%c", stack[stack_index].character);
	}
}