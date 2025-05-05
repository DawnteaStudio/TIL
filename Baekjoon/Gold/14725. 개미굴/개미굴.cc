#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct node
{
	vector<node*> vec;
	int		depth;
	string	value;
};

bool	cmp(node *a, node *b)
{
	return a->value < b->value;
}

void	input_node(node &head, vector<string> &tmp, int k)
{
	int i = 0;
	node *n = &head;
	bool	flag;

	while (i < k)
	{
		node *target;
		flag = false;
		for (int j = 0; j < n->vec.size(); j++)
		{
			if (n->vec[j]->value == tmp[i])
			{
				target = n->vec[j];
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			node *input = new node;
			input->value = tmp[i];
			input->depth = n->depth + 1;
			n->vec.push_back(input);
			target = input;
		}
		n = target;
		i++;
	}
}

void	print_node(node &head)
{
	int size = head.vec.size();
	if (head.depth >= 0)
	{
		for (int i = 0; i < head.depth; i++)
			cout << "--";
		cout << head.value << '\n';
	}
	sort(head.vec.begin(), head.vec.end(), cmp);
	for (int i = 0; i < size; i++)
		print_node(*head.vec[i]);
}

int main() {
	fast;
	int n, k;
	vector<string> tmp(15);
	cin >> n;


	node head;
	head.value = "test";
	head.depth = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
			cin >> tmp[j];
		input_node(head, tmp, k);
	}
	print_node(head);
}