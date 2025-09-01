#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

void solve(int depth, vector<int> &arr)
{
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[depth] = i;
		solve(depth + 1, arr);
	}
}

int main()
{
	fast;
	cin >> n >> m;
	vector<int> arr(n);
	solve(0, arr);
}
