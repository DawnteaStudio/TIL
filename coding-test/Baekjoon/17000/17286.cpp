#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

double res = 99999999;
vector<int> visited(4);

double get_d(pair<int, int> &a, pair<int, int> &b)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve(vector<pair<int, int> > &vec, vector<int> seq, int depth)
{
	if (depth == 4) {
		double tmp = 0;
		for (int i = 0; i < 3; i++)
			tmp += get_d(vec[seq[i]], vec[seq[i + 1]]);
		if (tmp < res)
			res = tmp;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (visited[i])
			continue;
		seq[depth] = i;
		visited[i] = 1;
		solve(vec, seq, depth + 1);
		visited[i] = 0;
	}
}

int main()
{
	fast;

	vector<pair<int, int> > vec(4);
	for (int i = 0; i < 4; i++)
		cin >> vec[i].first >> vec[i].second;
	vector<int> seq(4);
	seq[0] = 0;
	solve(vec, seq, 1);

	cout << (int)res;
}
