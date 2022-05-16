//공주님의 정원
#include <stdio.h>

int arr[416];

int	main()
{
	int m1, m2, d1, d2, n, ret = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d%d%d", &m1, &d1, &m2, &d2);
		if (arr[m1 * 32 + d1] < m2 * 32 + d2)
			arr[m1 * 32 + d1] = m2 * 32 + d2;
	}
	for (int i = 33; i < 383; i++)
	{
		if (m1 < arr[i])
			m1 = arr[i];
		if (d1 <= i && 96 < i)
		{
			d1 = m1;
			if (m1 <= i)
			{
				printf("0");
				return (0);
			}
			ret++;
		}
	}
	printf("%d\n",ret);	
}