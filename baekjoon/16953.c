//A -> B
#include <stdio.h>

int a, b, cnt = 1;

int main()
{
	scanf("%d %d", &a, &b);
	while (a < b)
	{
		if (b % 2 == 0)
			b /= 2;
		else if (b % 10 == 1)
			b /= 10;
		else
			break;
		cnt++;
	}
	printf("%d", a == b ? cnt : -1);
}