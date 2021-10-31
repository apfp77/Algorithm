#include <stdio.h>


int max(int d_3, int d_2, int d_1)
{
	int a;
	if (d_3 > d_2)
	{
		if (d_3 > d_1)
			a = d_3;
		else
			a = d_1;
	}
	else
		a = d_2 > d_1 ? d_2 : d_1;
	return a;
}

int main(void)
{
	int n;
	int d[10010];
	scanf("%d", &n);
	int m[n];
	int mx = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &m[i]);

	d[0] = m[0];
	mx = d[0];
	for (int i = 1; i < n; i++)
	{
		if (i < 2)
			d[i] = max(m[i-1] + m[i], m[i], d[i-1]);

		else if (i<3 && i>=2)
			d[i] = max(m[i-1] + m[i], d[i-2] + m[i], d[i-1]);
		
		else
			d[i] = max(d[i-3] + m[i-1] + m[i], d[i-2] + m[i], d[i-1]);
		mx = mx > d[i] ? mx : d[i];
	}
	printf("%d", mx);
}