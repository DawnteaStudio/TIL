#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void	postorder(vector<pair <char, char>> v, int i)
{
	char value = i + 'A';

	if (value != '.')
	{
		postorder(v, v[i].first - 'A');
		postorder(v, v[i].second - 'A');
		cout << (char)(i + 'A');
	}
}

void	inorder(vector<pair <char, char>> v, int i)
{
	char value = i + 'A';

	if (value != '.')
	{
		inorder(v, v[i].first - 'A');
		cout << (char)(i + 'A');
		inorder(v, v[i].second - 'A');
	}
}

void	preorder(vector<pair <char, char>> v, int i)
{
	char value = i + 'A';

	if (value != '.')
	{
		cout << (char)(i + 'A');
		preorder(v, v[i].first - 'A');
		preorder(v, v[i].second - 'A');
	}
}

void	print_tree(vector<pair <char, char>> v)
{
	preorder(v, 0);
	cout << '\n';
	inorder(v, 0);
	cout << '\n';
	postorder(v, 0);
}

int main()
{
	fast;

	vector<pair <char, char>> v(26);
	int n;
	char root, left, right;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> root >> left >> right;
		v[root - 'A'].first = left;
		v[root - 'A'].second = right;
	}
	print_tree(v);
	
}
