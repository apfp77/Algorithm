#include <stdio.h>
#include <stdlib.h>

typedef struct s_st
{
	int value;
	int cnt;
} t_st;

int	main(void)
{
	int su;
	scanf("%d",&su);
	t_st t_arr[1000001];
	int arr[su];
	t_st stack[su];
	int print[su];
	int arr_index;
	int stack_index;
	int print_index;
	int i;

	i = -1;
	stack_index = -1;
	arr_index = -1;
	while (++i < 1000001)
	{
		t_arr[i].value = 0;
		t_arr[i].cnt = 0;
	}
	while (++arr_index < su)
	{
		scanf("%d", &arr[arr_index]);
		t_arr[arr[arr_index]].value = arr[arr_index];
		t_arr[arr[arr_index]].cnt++;
	}

print_index = arr_index -1;
while (--arr_index > -1)
{
	while (stack_index >= 0 && stack[stack_index].cnt <= t_arr[arr[arr_index]].cnt)
		stack_index --;
	if (stack_index == -1)
		print[print_index] = -1;
	else
		print[print_index] =  stack[stack_index].value;
	
	stack_index++;
	stack[stack_index].value = t_arr[arr[arr_index]].value;
	stack[stack_index].cnt = t_arr[arr[arr_index]].cnt;
	print_index--;
}

while (++print_index < su)
	printf("%d ",print[print_index]);

	return (0);
}