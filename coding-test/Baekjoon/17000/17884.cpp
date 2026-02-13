#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
    cin >> n;
	vector<pair<int, int>> seq;
	int num;
	for (int i=1; i<=n-1; i++) {
		cin >> num;
		seq.emplace_back(num, i + 1);
	}
	sort(seq.begin(), seq.end());
	cout << 1 << " ";
	for (int i=0; i<n-1; i++) {
		cout << seq[i].second << " ";
	}
}