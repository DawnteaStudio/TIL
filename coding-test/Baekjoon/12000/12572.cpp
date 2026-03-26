#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first == p2.first)
        return p1.second > p2.second;
	return p1.first > p2.first;
}

int find_cross(vector<pair<int, int>>& left, vector<pair<int, int>>& right, int n) {
	int res = 0;
	for (int i=0; i<n; i++) {
		int idx = 0;
		while (right[idx].first > left[i].second) {
			if (right[idx].second < left[i].first)
				res++;
			idx++;
		}
	}
	return res;
}

int main()
{
	fast;
	int t;
    cin >> t;
	int n, a, b;
	for (int i=1; i<=t; i++) {
		cin >> n;
		vector<pair<int, int>> left, right;
		for (int j=0; j<n; j++) {
			cin >> a >> b;
			left.emplace_back(a, b);
			right.emplace_back(b, a);
		}
		sort(left.begin(), left.end(), cmp);
		sort(right.begin(), right.end(), cmp);
		cout << "Case #" << i << ": ";
		cout << find_cross(left, right, n) << '\n';
	}
}