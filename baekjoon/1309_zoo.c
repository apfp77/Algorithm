#include <stdio.h>

int	main(void)
{
	int n;
	scanf("%d", &n);
	int d[n][3];
	d[0][0] = 1;
	d[0][1] = 1;
	d[0][2] = 1;

	for (int i = 1; i < n; i++)
	{
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = d[i - 1][0] + d[i - 1][2] % 9901;
		d[i][2] = d[i - 1][0] + d[i - 1][1] % 9901;
	}

	printf("%d", (d[n - 1][0] + d[n - 1][1] + d[n - 1][2]) % 9901);
}