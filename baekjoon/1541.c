#include <stdio.h>

int	main(void)
{
	char c;
	int i, j,f = 0;
	for (scanf("%d",&i);scanf("%c",&c), c!= '\n';)
	{
		if (c == '-') f = 1;
		scanf("%d",&j);
		f ? (i -= j) : (i += j);
	}
	printf("%d\n",i);
}