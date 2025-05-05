#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void	find_childs(int parent, int num, vector<int> &v, vector<vector<int>> &do_not_know_parent)
{
	if (v[num] != 0)
		return ;
	v[num] = parent;
	for (int i = 0; i < do_not_know_parent[num].size(); i++)
		find_childs(num, do_not_know_parent[num][i], v, do_not_know_parent);
}

int main()
{
	fast;

	int n;
	cin >> n;

	int num1, num2;
	vector<int> v(n + 1, 0);
	vector<vector<int>> do_not_know_parent(n + 1);
	v[1] = -1;

	for (int i = 1; i < n; i++)
	{
		cin >> num1 >> num2;
		if (v[num1] != 0)
		{
			v[num2] = num1;
			for (int j = 0; j < do_not_know_parent[num2].size(); j++)
				find_childs(num2, do_not_know_parent[num2][j], v, do_not_know_parent);
		}
		else if (v[num2] != 0)
		{
			v[num1] = num2;
			for (int j = 0; j < do_not_know_parent[num1].size(); j++)
				find_childs(num1, do_not_know_parent[num1][j], v, do_not_know_parent);
		}
		else
		{
			do_not_know_parent[num1].push_back(num2);
			do_not_know_parent[num2].push_back(num1);
		}
	}
	for (int i = 2; i < n + 1; i++)
		cout << v[i] << '\n';
}
