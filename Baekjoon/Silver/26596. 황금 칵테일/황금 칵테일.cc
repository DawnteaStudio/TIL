#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool	cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}

int main() {
	fast;
	int n, ml;
	string str;
	cin >> n;

	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> str >> ml;
		if (m.find(str) == m.end())
			m.insert(make_pair(str, ml));
		else
			m.find(str)->second += ml;
	}
	vector<pair<string, int> > vec;
	for (map<string, int>::iterator i = m.begin(); i != m.end(); i++)
		vec.push_back(make_pair(i->first, i->second));
	sort(vec.begin(), vec.end(), cmp);
	for (vector<pair<string, int> >::iterator i = vec.begin(); i != vec.end(); i++)
	{
		for (vector<pair<string, int> >::iterator j = i + 1; j != vec.end(); j++)
		{
			if (static_cast<int>(i->second * 1.618) == j->second)
			{
				cout << "Delicious!";
				return 0;
			}
		}
	}
	cout << "Not Delicious...";
}
