#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long res;

int main() {
	fast;
    
	int n;
	cin >> n;

	vector<long long> vec(n);
	vector<long long> dp(n, 0);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = vec[i + 1] + dp[i + 1];
	}

	for (int i = 0; i < n - 1; i++) {
		res += dp[i] * vec[i];
		res %= 1000000007;
	}
	cout << res;
}
