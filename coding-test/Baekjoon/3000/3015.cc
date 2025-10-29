#include <iostream>
#include <stack>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long ans;

int main() {
	fast;
	
	int n;
	cin >> n;

	stack<pair<int, long long> > s;
	for (int i = 0; i < n; i++) {
		int tmp;
		long long same = 0;
		cin >> tmp;

		while (!s.empty() && s.top().first <= tmp) {
			ans += s.top().second;
			if (s.top().first == tmp)
				same = s.top().second;
			s.pop();
		}
		if (!s.empty())
			ans++;
		s.push({tmp, same + 1});
	}
	cout << ans;
}
