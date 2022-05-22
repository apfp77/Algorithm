//롤러코스터
#include <stdio.h>

int s[1000][1000], r, c;

void r_hol()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c - 1; j++)
			printf((i % 2) ? "L" : "R");
		if (i != r - 1)
			printf("D");
	}
}

void c_hol()
{
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < r - 1; i++)
			printf((j % 2) ? "U" : "D");
		if (j != c - 1)
			printf("R");
	}
}

int main()
{
	int m_i, m_j, min = 1001;
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &s[i][j]);
			if (min > s[i][j] && (i + j) % 2 == 1)
			{
				m_i = i;
				m_j = j;
				min = s[i][j];
			}
		}
	if (r % 2 != 0)
		r_hol();
	else if (r % 2 == 0 && c % 2 != 0)
		c_hol();
	else
	{
		int tmp = m_i;
		if (m_i % 2)
			tmp--;
		for (int i = 0; i < tmp; i++)
		{
			for (int j = 0; j < c - 1; j++)
				printf((i % 2) ? "L" : "R");
			if (i != r - 1)
				printf("D");
		}
		for (int i = 0; i < m_j; i++)
			printf((i % 2) ? "UR" : "DR");
		for (int i = m_j; i < c - 1; i++)
			printf((i % 2) ? "RU" : "RD");
		for (int i = tmp + 2; i < r; i++)
		{
			printf("D");
			for (int j = 0; j < c - 1; j++)
				printf((i % 2) ? "R" : "L");
		}
	}
}
