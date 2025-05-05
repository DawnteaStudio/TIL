#include <iostream>
#include <algorithm>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	fast;
	int n;
	cin >> n;
	pair<int, int> arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';
}

