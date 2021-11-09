#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int m[n];
	int d[11] ={1,2,4,7};
	for (int i = 0; i < n; i++)
		scanf(" %d", &m[i]);
	
	for (int i = 4; i < 11; i++)
		d[i] = d[i-1] + d[i-2] + d[i-3];
	
	for (int i = 0; i < n; i++)
		printf("%d\n", d[m[i]-1]);
}