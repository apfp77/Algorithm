#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	int buf;
	int size;
	scanf("%d", &n);
	char arr[n][80];
	int print[n];
	
	for (int i = 0; i < n; i++)
		print[i] = 0;	

	for (int i = 0; i < n; i++)
	{
		scanf(" %s", arr[i]);
		size = strlen(arr[i]);
		buf = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 'O' || arr[i][j] == 'o')
				print[i] += ++buf;
			else
				buf = 0;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", print[i]);
}