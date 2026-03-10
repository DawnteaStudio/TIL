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

	stack<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		while (!s.empty() && s.top().first < tmp) {
			res += s.top().second;
			s.pop();
		}
		if (s.empty())
			s.push({tmp, 1});
		else {
			if (s.top().first == tmp) {
				res += s.top().second;
				s.top().second++;
				if (s.size() > 1)
					res++;
			}
			else {
				res++;
				s.push({tmp, 1});
			}
		}
	}
	cout << res;
}
