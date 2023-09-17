// 01타일
#include <cstdio>
#define RET_MODE 15746

int main(){
	int n, a, b;
	bool flag = false;
	scanf("%d", &n);
	a = 1;
	b = 1;

	for (int i = 2; i <= n; i++){
		flag = !flag;
		if (flag){
			b = (a + b) % 15746;
		}
		else
			a = (a + b) % 15746;
	}
	printf("%d\n", flag ? b:a);
}
/*
	1	또는 00만 가능

	1
	1
	
	2
	00, 11

	3
	001, 100, 111

	4 
	0000, 0011, 1001, 1100, 1111
*/
