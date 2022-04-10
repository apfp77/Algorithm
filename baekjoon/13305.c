#include <stdio.h>

int	main(void)
{
	int n, length[99999], buf = 0, tmp = 0;
	long long oil = 0;

	scanf("%d",&n);
	for (int i = 0; i < n - 1; i++)
		scanf("%d",&length[i]);
	scanf("%d", &buf);
	for (int i = 0; i < n - 1; i++)
	{
		oil += (long long)buf * length[i];
		scanf("%d", &tmp);
		if (buf > tmp)
			buf = tmp;
	}
	printf("%lld\n", oil);
}