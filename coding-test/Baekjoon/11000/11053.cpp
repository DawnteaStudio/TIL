#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void solve(int v, vector<int> &arr, vector<int> &ans)
{
	int start = 0;
	int end = ans.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (ans[mid] >= v)
			end = mid - 1;
		else
			start = mid +    1;
	}
	ans[start] = v;
}

int main() {
	fast;
    
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> ans;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ans.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		int len = ans.size() - 1;
		if (arr[i] > ans[len])
			ans.push_back(arr[i]);
		else
			solve(arr[i], arr, ans);
	}
	cout << ans.size();
}
