#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct cmp
{
	bool operator()(pair<int, int> &a, pair<int, int> &b)
	{
		if (a.second > b.second)
		{
			if (b.second == -1)
				return false;
			return true;
		}
		if (a.second == -1)
			return true;
		return false;
	}
};


int main() {
	fast;
	int n, m, start, goal, cost;
	cin >> n >> m;
	vector<vector<pair<int, int> > > vec(n + 1);
	vector<bool> visited(n + 1, false);
	vector<int> dist(n + 1, -1);
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > q;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> goal >> cost;
		vec[start].push_back(make_pair(goal, cost));
	}
	cin >> start >> goal;
	dist[start] = 0;
	q.push(make_pair(start, 0));
	while (!q.empty())
	{
		int target = q.top().first;
		int size = vec[target].size();
		q.pop();
		if (visited[target] == false)
		{
			visited[target] = true;
			for (int i = 0; i < size; i++)
			{
				if (dist[vec[target][i].first] == -1)
					dist[vec[target][i].first] = dist[target] + vec[target][i].second;
				else if (dist[target] + vec[target][i].second < dist[vec[target][i].first])
					dist[vec[target][i].first] = dist[target] + vec[target][i].second;
				q.push(make_pair(vec[target][i].first, dist[vec[target][i].first]));
			}
		}
	}
	cout << dist[goal] << '\n';
}