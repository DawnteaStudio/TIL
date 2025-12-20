// Farm
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	int cnt = 0;
	pair<int, int> answer;
	for (int i = 1; i < n; i++) {
		if (a * i + b * (n - i) == w) {
			cnt++;
			if (cnt == 1) {
				answer.first = i;
				answer.second = n - i;
			}
			else break ;
		}
	}
	if (cnt == 1)
		cout << answer.first << " " << answer.second;
	else cout << -1;
	return (0);
}