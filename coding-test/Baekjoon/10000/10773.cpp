#include <iostream>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, tmp;
	cin >> n;

	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 0)
			s.pop();
		else
			s.push(tmp);
	}
	int res = 0;
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}
	cout << res;
}
