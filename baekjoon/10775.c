//공항
#include <stdio.h>

int gate[100001];

int find(int val)
{
	if (gate[val] == val)
		return val;
	gate[val] = find(gate[val]);
	return gate[val];
}

int main()
{
	int g, p, ret = 0, tmp, docking, i;
	scanf("%d%d",&g, &p);
	for (i = 1; i <= g; i++)
		gate[i] = i;
	for (i = 1; i <= p; i++, ret++)
	{
		scanf("%d",&tmp);
		docking = find(tmp);

		if (docking == 0)
			break;
		gate[docking] = gate[docking - 1];
	}
	printf("%d\n",ret);
}

