#include <iostream>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, tmp;
	long long res = 0;
	cin >> n;

	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		while (!s.empty() && s.top() <= tmp)
			s.pop();
		if (s.empty())
			s.push(tmp);
		else {
			res += s.size();
			s.push(tmp);
		}
	}
	cout << res;
}
