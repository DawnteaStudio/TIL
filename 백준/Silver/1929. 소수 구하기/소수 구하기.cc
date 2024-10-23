#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, m;
	cin >> n >> m;

	vector<bool> prime(m + 1, true);
	prime[1] = false;
	for (int i = 2; i <= m; i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * 2; j <= m; j += i)
				prime[j] = false;
		}
	}
	for (int i = n; i <= m; i++)
	{
		if (prime[i])
			cout << i << '\n';
	}
}