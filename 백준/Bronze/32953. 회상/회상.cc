#include <iostream>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, stu, id, res = 0;
	map<int, int> check;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> stu;
		for (int j = 0; j < stu; j++) {
			cin >> id;
			if (check.find(id) == check.end())
				check[id] = 1;
			else
				check[id]++;
		}
	}

	for (map<int, int>::iterator iter = check.begin(); iter != check.end(); iter++) {
		if (iter->second >= m)
			res++;
	}
	cout << res;
}