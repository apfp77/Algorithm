#include <stdio.h>

int	main(void)
{
	int num[2];
	int n;
	int temp;
	scanf("%lld", &n);
	num[0] = 1;
	num[1] = 1;
	for (int i = 1; i < n; i++)
	{
		temp = num[1];
		num[1] = (num[0] + num[1]) % 10007;
		num[0] = temp;
	}
	
	printf("%lld\n", num[1]);	
}