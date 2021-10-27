#include <stdio.h>

int	main(void)
{
	int n;
	int d[15] = {0, 3, 11, 0,};

	scanf("%d", &n);
	if (n % 2 != 0)
	{
		printf("%d\n", 0);
		return (0);
	}
	for (int i = 3; i <= n / 2; i++)
		d[i] = 4 * d[i-1] - d[i-2];

	printf("%d\n", d[n/2]);
}