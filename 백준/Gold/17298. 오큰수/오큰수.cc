#include <iostream>
#include <stack>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, tmp, v = 0;
	cin >> n;

	vector<int> vec(n);
	stack<pair<int, int>> s;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		while (!s.empty() && s.top().first < tmp) {
			vec[s.top().second] = tmp;
			s.pop();
		}
		s.push({tmp, i});
	}
	while (!s.empty()) {
		vec[s.top().second] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
}
