#include <iostream>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int n, tmp, res = 0;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		res += tmp;
		if (tmp != 0)
			s.push(tmp);
		else
		{
			res -= s.top();
			s.pop();
		}
	}
	cout << res;
}
