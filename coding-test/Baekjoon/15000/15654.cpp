#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

void solve(int depth, vector<int> &arr, set<int> &visited, vector<int> &nums)
{
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited.find(nums[i]) != visited.end())
			continue;
		visited.insert(nums[i]);
		arr[depth] = nums[i];
		solve(depth + 1, arr, visited, nums);
		visited.erase(nums[i]);
	}
}

int main()
{
	fast;
	cin >> n >> m;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	vector<int> arr(n);
	set<int> visited;
	solve(0, arr, visited, nums);
}
