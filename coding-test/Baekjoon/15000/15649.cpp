#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

void solve(int depth, vector<int> &arr, vector<int> &visited)
{
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		visited[i] = 1;
		arr[depth] = i;
		solve(depth + 1, arr, visited);
		visited[i] = 0;
	}
}

int main()
{
	fast;
	cin >> n >> m;
	vector<int> visited(n + 1, 0);
	vector<int> arr(n);
	solve(0, arr, visited);
}
