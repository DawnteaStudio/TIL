#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
	if (a.first > b.first)
		return true;
	if (a.first == b.first)
		return a.second < b.second;
	return false;
}

int main()
{
	fast;
	int a, b, c, n, m, k;
	cin >> n >> m >> k >> a >> b >> c;

	vector<pair<int, string> > vec(3);
	vec[0] = {n * a, "Joffrey"};
	vec[1] = {m * b, "Robb"};
	vec[2] = {k * c, "Stannis"};
	sort(vec.begin(), vec.end(), cmp);
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (cnt > vec[i].first)
			break;
		cout << vec[i].second << " ";
		cnt = vec[i].first;
	}
}
