#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<string, int> &p1, pair<string, int> &p2) {
	if (p1.second == p2.second)
        return p1.first < p2.first;
	return p1.second > p2.second;
}

int main()
{
	fast;
	int n;
    cin >> n;
	string name;
	int b;
	vector<pair<string, int>> vote;
	for (int i=0; i<n; i++) {
		cin >> name >> b;
		vote.emplace_back(name, b);
	}
	sort(vote.begin(), vote.end(), cmp);
	cout << vote.begin()->first;
}