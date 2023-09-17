// LCS
#include <iostream>
#define MAX_SIZE 1001
using namespace std;

int dp[MAX_SIZE][MAX_SIZE];

int main(){
	string str1;
	string str2;
	cin >> str1 >> str2;
	
	
	for (int i = 0; i < str2.length(); i++)
	{
		for (int j = 0; j < str1.length(); j++)
		{
			if (str2[i] == str1[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

		}
	}
	cout << dp[str2.length()][str1.length()] << '\n';
}

/*
			A	C	A	Y	K	P
		0	0	0	0	0	0	0
	C	0	0	1	1	1	1	1
	A	0	1 1 2 2 2 2
	P	0 1 1 2 2 2 3 
	C	0 1 2 2 2 2 3
	A	0 2 2 3 3 3 3
	K	0 2 2 3 3 4 4
*/
 
 /*
			A B A A B A
		0 0 0 0 0 0 0
	A 0 1 1 2 3 3 4
	A 0	2 2 2 4 4 5
 */
 