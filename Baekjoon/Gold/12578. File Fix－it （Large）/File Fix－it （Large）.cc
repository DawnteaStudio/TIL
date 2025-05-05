#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct computer
{
	map<string, computer*> files;
};

void	insert(computer *head, string &input, bool make, int &res)
{
	computer *node = head;
	string tmp;

	for (int i = 0; i <= input.length(); i++)
	{
		if (i == input.length() || input[i] == '/')
		{
			if (i != 0)
			{
				if (node->files.find(tmp) == node->files.end())
				{
					node->files[tmp] = new computer;
					if (make)
						res++;
				}
				node = node->files[tmp];
			}
			tmp = "";
		}
		else
			tmp += input[i];
	}


}

int main() {
	fast;
	int t, res;
	string input;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		res = 0;
		computer head;
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			insert(&head, input, false, res);
		}
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			insert(&head, input, true, res);
		}
		cout << "Case #" << i << ": " << res << '\n';
	}
}