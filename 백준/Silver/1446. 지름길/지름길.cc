#include <iostream>
#include <cmath>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, d;
	cin >> n >> d;

	vector<vector<pair<int, int> > > vec(d + 1);
	vector<int> dist(d + 1);
	for (int i = 0; i <= d; i++)
		dist[i] = i;

	int start, goal, len;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> goal >> len;
		if (goal > d || goal - start <= len)
			continue;
		vec[start].push_back(make_pair(goal, len));
	}
	int prev = 0;
	for (int i = 0; i <= d; i++)
	{
		if (i != 0)
		{
			prev = dist[i - 1];
			dist[i] = min(dist[i - 1] + 1, dist[i]);
		}
		if (!vec[i].empty())
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				if (dist[vec[i][j].first] > dist[i] + vec[i][j].second)
					dist[vec[i][j].first] = dist[i] + vec[i][j].second;
			}
		}
	}
	cout << dist[d];
}