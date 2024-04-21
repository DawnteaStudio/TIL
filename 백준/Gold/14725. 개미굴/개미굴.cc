#include <iostream>
#include <string>
#include <map>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct node
{
	map<string, node *> m;
};

node *head;
void print(node *cur, string depth)
{
	for (auto s : cur->m)
	{
		cout << depth + s.first << "\n";
		print(s.second, depth + "--");
	}
}

int main()
{
	fast;
	int N, K;
	string food;
	head = new node;
	cin >> N;
	while (N--)
	{
		cin >> K;
		node *cur = head;
		while (K--)
		{
			cin >> food;
			if (cur->m.find(food) == cur->m.end())
				cur->m[food] = new node;
			cur = cur->m[food];
		}
	}
	print(head, "");
}