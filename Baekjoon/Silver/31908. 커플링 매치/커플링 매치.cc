#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int n, cnt = 0;
	string name, ring;
	map <string, pair<vector<string>, int> > m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> ring;
		if (ring == "-")
			continue;
		if (m.find(ring) == m.end())
		{
			vector<string> tmp(1, name);
			pair<vector<string>, int> m_tmp;
			m_tmp.first = tmp;
			m_tmp.second = 1;
			m.insert(make_pair(ring, m_tmp));
		}
		else
		{
			m.find(ring)->second.first.push_back(name);
			m.find(ring)->second.second++;
			if (m.find(ring)->second.second == 2)
				cnt++;
			else if (m.find(ring)->second.second == 3)
				cnt--;
		}
	}

	cout << cnt << '\n';
	for (map<string, pair<vector<string>, int> >::iterator i = m.begin(); i != m.end(); i++)
	{
		if (i->second.second == 2)
			cout << i->second.first[0] << " " << i->second.first[1] << '\n';
	}
}
