#include <stdio.h>

int	main(void)
{
	int t;
	scanf("%d", &t);
	int n[t];
	int d_zero[41] = {1,0,};
	int d_one[41] = {0,1,0,};
	int mx = 0;
	for (int i = 0; i < t; i++)
	{
		scanf(" %d", &n[i]);
		mx = n[i] > mx ? n[i] : mx;
	}
	for (int i = 2; i <= mx; i++)
	{
		d_zero[i] = d_zero[i-1] + d_zero[i - 2];
		d_one[i] = d_one[i-1] + d_one[i - 2];

	}	
	for (int i = 0; i < t; i++)
	{
		printf("%d %d\n", d_zero[n[i]], d_one[n[i]]);
	}
}