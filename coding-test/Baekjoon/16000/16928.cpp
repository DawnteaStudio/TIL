#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	
	int n, m;
	cin >> n >> m;

	vector<int> event(101, 0);
	vector<int> dp(101, 999999);

	int a, b;
	for (int i = 0; i < n + m; i++) {
		cin >> a >> b;
		event[a] = b;
	}

	dp[1] = 0;
	for (int i = 1; i < 100; i++) {
		if (event[i])
			continue;
		for (int j = 1; j <= 6; j++) {
			int now = i + j;
			if (now > 100)
				break;
			if (dp[now] > dp[i] + 1)
				dp[now] = dp[i] + 1;
			if (event[now]) {
				if (dp[event[now]] > dp[now]) {
					dp[event[now]] = dp[now];
					if (event[now] < i)
						i = event[now] - 1;
				}
			}
		}
	}
	cout << dp[100];
}
