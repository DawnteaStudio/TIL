#include <iostream>
#include <vector>
#include <map>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, t, res;
	string value, id;
	map<string, vector<string> > m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		res = 1;
		m.clear();
		for (int j = 0; j < t; j++)
		{
			cin >> value >> id;
			m[id].push_back(value);
		}
		for (map<string, vector<string> >::iterator iter = m.begin(); iter != m.end(); iter++)
			res *= (*iter).second.size() + 1;
		cout << res - 1 << '\n';
	}
}