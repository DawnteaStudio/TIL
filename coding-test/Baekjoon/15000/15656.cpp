#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

void solve(int depth, vector<int> &arr, vector<int> &nums)
{
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[depth] = nums[i];
		solve(depth + 1, arr, nums);
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
	solve(0, arr, nums);
}
