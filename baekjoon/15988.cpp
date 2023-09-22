// 1, 2, 3 더하기 3
#include <cstdio>

#define MAX_SIZE 1000001
#define RET_MODE 1000000009

using namespace std;

int dp[MAX_SIZE] = {1,1,2};

int main()
{
	int n, tmp;
	scanf("%d", &n);
	for (int i = 3; i < MAX_SIZE; i++)
			dp[i] = ((dp[i - 1] + dp[i - 2]) % RET_MODE + dp[i - 3]) % RET_MODE;
	while (n--)
	{
		scanf("%d", &tmp);
		printf("%d\n", dp[tmp]);
	}
	return 0;
}

/*
	dp[0] = 1
	dp[1] = 1
	dp[2] = 2
	dp[3] = 4
	dp[4] = 7
	dp[5] = 13
	dp[6] = 24
	dp[7] = 44
	dp[8] = 81
	dp[9] = 149
	dp[10] = 274
*/
