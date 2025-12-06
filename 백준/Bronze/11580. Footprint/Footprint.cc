#include <iostream>
#include <set>
#include <utility>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n;
	int y = 0, x = 0;
	cin >> n;

	string str;
	cin >> str;

	set<pair<int, int> > s;
	s.insert({0, 0});

	for (int i = 0; i < n; i++) {
		switch (str[i])
		{
		case 'S':
			y--;
			break;
		case 'N':
			y++;
			break;
		case 'E':
			x++;
			break;
		case 'W':
			x--;
			break;
		default:
			break;
		}
		s.insert({y, x});
	}
	cout << s.size();
}