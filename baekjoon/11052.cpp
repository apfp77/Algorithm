// 카드 구매하기
#include <cstdio>

#define MAX_SIZE 1001
using namespace std;

int n, dp[MAX_SIZE];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dp[i]);
		for (int j = 1; j < i && j <= i - j; j++)
			dp[i] = dp[i] > dp[i - j] + dp[j] ? dp[i] : dp[i - j] + dp[j];
	}
	printf("%d\n", dp[n]);
}
