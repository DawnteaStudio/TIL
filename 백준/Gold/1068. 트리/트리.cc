#include <iostream>
#include <vector>
#include <queue>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int n, parent, remove, cnt = 0;
	queue <int> q;
	cin >> n;

	int num_of_childs[50] = {0};
	int name_of_parent[50];
	vector<vector<int>> name_of_childs(n);

	for (int i = 0; i < n; i++)
	{
		cin >> parent;
		if (parent == -1)
			continue;
		name_of_parent[i] = parent;
		num_of_childs[parent]++;
		name_of_childs[parent].push_back(i);
	}

	cin >> remove;
	num_of_childs[name_of_parent[remove]]--;
	q.push(remove);
	while (!q.empty())
	{
		remove = q.front();
		q.pop();
		num_of_childs[remove] = -1;
		for (int i = 0; i < name_of_childs[remove].size(); i++)
		{
			if (num_of_childs[name_of_childs[remove][i]] > 0)
				q.push(name_of_childs[remove][i]);
			else
				num_of_childs[name_of_childs[remove][i]] = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num_of_childs[i] == 0)
			cnt++;
	}
	cout << cnt;
}
