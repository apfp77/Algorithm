//멀티탭 스케줄링
#include <stdio.h>

int tab[101], use[101];

int	main()
{
	int n, k,i, flag, j,z, ret = 0, tmp, tmp2;
	scanf("%d%d",&n,&k);
	for (i = 0; i < k; i++)
		scanf("%d", &use[i]);
	
	for (i = 0; i < k; i++)
	{
		flag = 0;
		for (j = 0; j < n; j++)
		{
			if (tab[j] == use[i])
			{
				flag = 1;
				break;
			}
			if (!tab[j])
			{
				tab[j] = use[i];
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			ret++;
			tmp = 0;
			for (j = 0; j < n; j++)
			{
				for (z = i + 1; z < k && tab[j] != use[z]; z++)
					;
				if (z > tmp)
					tmp = z, tmp2 = j;
			}
			tab[tmp2] = use[i];
		}
	}
	printf("%d\n",ret);
}