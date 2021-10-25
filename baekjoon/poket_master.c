#include <stdio.h>

int n,m;
int g_num;

int ft_strlen(char *arr)
{
	int i = -1;

	while (arr[++i]);
	return (i);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

//문자를 숫자로 변환해주는 함수
int char_integer(char *arr)
{
	int num = 0;
	int size = ft_strlen(arr);
	for (int i = 0; i < size; i++)
		num = num * 10 + (arr[i] - '0');
	return (num);
}

//j번쨰에 있다 이것을 나눠서 넣어준다
void integer_char(int j, char print[][21], int p_i)
{
	int temp = j % 10;
	if (j == 0)
		return ;
	integer_char(j / 10, print, p_i);
	print[p_i][g_num] = temp + '0';
	g_num++;
}

int	main(void)
{
	scanf("%d %d", &n, &m);
	char pocketmon[n][21];
	char qa[m][21];
	char result[m][21];
	char print[m][21];
	int p_i = 0;
	int buf;

	for (int i = 0; i < n; i++)
		scanf(" %s", pocketmon[i]);
	
	for (int i = 0; i < m; i++)
		scanf(" %s", qa[i]);

	for (int i = 0; i < m; i++)
	{
		buf = 0;
		if (qa[i][0] >= '1' && qa[i][0] <= '9')
			buf = char_integer(qa[i]);
		//문자일때
		if (!buf)
		{
			for (int j = 0; j < n; j++)
				if (pocketmon[j][0] == qa[i][0])
					if (ft_strcmp(pocketmon[j], qa[i]))
					{
						//숫자로 변환이니까 j를 가지고 대입
						g_num = 0;
						integer_char(j + 1, print, p_i);
						p_i++;
						break;
					}
		}
		//숫자일때
		else
		{
			int size = ft_strlen(pocketmon[buf - 1]);
			for (int j = 0; j < size; j++)
			{ 
				print[p_i][j] = pocketmon[buf - 1][j];
			}
			p_i++;
		}
	}
	for (int i = 0; i < p_i; i++)
		printf("%s\n", print[i]);
	
}