#include <iostream>
#include <map>
#include <utility>
#include <queue>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, k;
	queue<pair<int, int> > q;
	map<int, int> m;
	cin >> n >> k;
	int res = abs(n - k);
	if (k <= n)
		cout << res;
	else
	{
		m.insert(make_pair(0, 0));
		q.push(make_pair(n, 0));
		while (!q.empty())
		{
			int now = q.front().first;
			int cost = q.front().second;
			q.pop();
			if (now == k)
			{
				if (res > cost)
					res = cost;
			}
			else if (now > k)
			{
				if (res > now - k + cost)
					res = now - k + cost;
			}
			else
			{
				if (m.find(2 * now) == m.end() || m.find(2 * now)->second > cost + 1)
				{
					m.insert(make_pair(2 * now, cost + 1));
					q.push(make_pair(2 * now, cost + 1));
				}
				if (m.find(now + 1) == m.end() || m.find(now + 1)->second > cost + 1)
				{
					m.insert(make_pair(now + 1, cost + 1));
					q.push(make_pair(now + 1, cost + 1));
				}
				if (now - 1 > 0 && m.find(now - 1) == m.end() || m.find(now - 1)->second > cost + 1)
				{
					m.insert(make_pair(now - 1, cost + 1));
					q.push(make_pair(now - 1, cost + 1));
				}
			}
		}
		cout << res;
	}
}