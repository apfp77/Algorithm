// 쉬운 계단 수
#include <cstdio>
#define MAX_SIZE 101
#define RET_MODE 1000000000
using namespace std;

int n;
long long dp[MAX_SIZE][11], ret;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < 10; i++){
		dp[1][i] = 1;
		dp[2][i] = 2;
	}
	dp[2][9] = 1;

	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (j == 1){
				dp[i][j] = (dp[i - 2][j] + dp[i - 1][j + 1]) % RET_MODE;
			}
			else
				dp[i][j] = (dp[i - 1][j - 1] +  dp[i - 1][j + 1]) % RET_MODE;
		}
	}
	
	for (int i = 1; i < 10; i++)
		ret += (dp[n][i]);
	printf("%lld\n", ret % RET_MODE);
}
/*
	1  = 9
	1,2,3,4,5,6,7,8,9

	2 = 17
	10, 12, 
	21, 23, 
	32, 34, 
	43, 45, 
	54, 56, 
	65, 67, 
	76, 78, 
	87, 89, 
	98

	3
	101, 123, 121, 
	210, 212, 234, 232, 
	345, 321, 323, 343, 
	456, 432, 434, 454,
	567, 543, 545, 565,
	678, 654, 656, 676,
	789, 765, 765, 787
	876, 878, 898, 
	987, 989, 

	4
	1010, 1012, 1210, 1212, 1234, 1232

	i가 1일땐
		dp[n][i] = dp[n - 2][i] + dp[n - 1][i + 1];
	나머진
		dp[n][i] = dp[n - 1][i - 1] +  dp[n - 1][i + 1]
*/
