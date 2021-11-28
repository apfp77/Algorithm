//집합
#include <stdio.h>
#include <stdbool.h>

bool check[21];

int	main(void)
{
	int m, num;
	char str[10];
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);
		//add
		if (str[2] == 'd')
		{
			scanf(" %d", &num);
			check[num] = true;
		}
		//remove
		else if (str[2] == 'm')
		{
			scanf(" %d", &num);
			check[num] = false;
		}
		//check
		else if (str[2] == 'e')
		{
			scanf(" %d", &num);
			printf("%d\n", check[num]);	
		}
		//toggle
		else if (str[2] == 'g')
		{
			scanf(" %d", &num);
			check[num] = check[num] == true ? false : true;
		}
		//all
		else if (str[2] == 'l')
		{
			for (int i = 0; i < 21; i++)
				check[i] = true;
		}
		//empty
		else if (str[2] == 'p')
		{
			for (int i = 0; i < 21; i++)
				check[i] = false;
		}
	}	
}