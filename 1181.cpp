#include <iostream>
#include <set>
using namespace std;

int n;
set<pair<int, string> > ret;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--)
	{
		string tmp;
		cin >> tmp;
		int size = tmp.length();
		ret.insert(make_pair(size, tmp));
	}
	for (auto& t: ret)
		cout << t.second.data() << '\n';
}

