#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;
void solve(int depth, vector<int> &arr, vector<int> &visited, vector<int> &nums, set<string> &inputs, string res) {
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 1)
			continue;
		string tmp = "";
		tmp = res + " " + to_string(nums[i]);
		if (inputs.find(tmp) != inputs.end()) {
			continue;
		}
		inputs.insert(tmp);
		visited[i] = 1;
		arr[depth] = nums[i];
		solve(depth + 1, arr, visited, nums, inputs, tmp);
		visited[i] = 0;
	}
}

int main(void) {
	fast;

	cin >> n >> m;
	set<string> inputs;

	vector<int> arr(m);
	vector<int> nums(n);
	vector<int> visited(n, 0);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	string tmp = "";
	solve(0, arr, visited, nums, inputs, tmp);
}
