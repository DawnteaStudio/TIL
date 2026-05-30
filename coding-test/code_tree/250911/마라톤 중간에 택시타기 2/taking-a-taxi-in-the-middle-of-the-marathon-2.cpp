#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res = INT_MAX;

int main() {
	fast;
    
	int n;
	cin >> n;
	vector<pair<int, int> > vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;

	for (int i = 1; i < n - 1; i++) {
		int tmp = 0;
		for (int j = 1; j < n; j++) {
			if (j == i)
				continue;
			if (j == i + 1)
				tmp += abs(vec[j].first - vec[j - 2].first) + abs(vec[j].second - vec[j - 2].second);
			else
				tmp += abs(vec[j].first - vec[j - 1].first) + abs(vec[j].second - vec[j - 1].second);
		}
		if (tmp < res)
			res = tmp;
	}
	cout << res;
}
