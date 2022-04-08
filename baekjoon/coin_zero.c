//동전 0

#include <stdio.h>

int	main()
{
	int n, k, i;
	i = 0;
	scanf("%d %d", &n, &k);
	int b[n];
	for (; i < n; i++)
		scanf(" %d",&b[i]);
	i--;
	n = 0;
	while (k != 0)
	{
		while (b[i] > k)
			i--;
		n += k / b[i];
		k = k % b[i];
	}
	printf("%d",n);
}