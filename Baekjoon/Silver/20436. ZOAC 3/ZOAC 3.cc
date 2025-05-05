#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct key
{
	char c;
	int x = 0;
	int y = 0;
};

int find_len(char c, vector<vector<char> > &vec, key &left, key &right)
{
	int len = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == c)
			{
				if (i < 2 && j >= 5 || i == 2 && j >= 4)
				{
					len += right.y - i > 0 ? right.y - i : i - right.y;
					len += right.x - j > 0 ? right.x - j : j - right.x;
					right.y = i;
					right.x = j;
					return len;
				}
				else
				{
					len += left.y - i > 0 ? left.y - i : i - left.y;
					len += left.x - j > 0 ? left.x - j : j - left.x;
					left.y = i;
					left.x = j;
					return len;
				}
			}
		}
	}
}

int main()
{
	fast;
	key left, right;
	string str;
	int l, r, res = 0;
	cin >> left.c >> right.c >> str;

	int len = str.length();
	vector<vector<char> > vec(3);
	vec[0] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
	vec[1] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
	vec[2] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == left.c)
			{
				left.y = i;
				left.x = j;
			}
			if (vec[i][j] == right.c)
			{
				right.y = i;
				right.x = j;
			}
		}
	}
	for (int i = 0; i < len; i++)
		res += find_len(str[i], vec, left, right);
	res += len;
	cout << res;
}
