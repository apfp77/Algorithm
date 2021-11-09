#include <stdio.h>

int	main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	long long int d[n + 1][k + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			d[i][j] = 0;
	
	for (int i = 0; i <= k; i++)
		d[0][i] = 1;
	
	for (int i = 1; i <= n; i++)
		d[i][1] = 1;	

	//3, 3 일경우 d3,2 d2,2 d1,2 d0,2 를 더해야한다
	//3, 2 는 0,1 ~ ~ 3,1 까지 더한 수
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= k; j++)
			for (int z = 0; z <= i; z++)
				d[i][j] = (d[i][j] + d[z][j - 1]) % 1000000000;

	printf("%lld\n", d[n][k]);
}