//탑
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
stack<pair<int, int> > st;
string ret;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		while (!st.empty())
		{
			if (tmp < st.top().second){
				ret += (to_string(st.top().first) + ' ');
				break;
			}
			st.pop();
		}
		if (st.empty())
			ret += "0 ";
		st.push(make_pair(i + 1, tmp));
	}
	cout << ret;
}
