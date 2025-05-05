#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, res = 0;
	cin >> n;
	int s1, s2;
	vector<pair<string, int> > vec(n);
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		vec[i] = (make_pair(str, 0));
	}
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			if (vec[j].first == str)
			{
				vec[j].second = i;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		s1 = vec[i].second;
		for (int j = i + 1; j < n; j++)
		{
			s2 = vec[j].second;
			if (s1 < s2)
				res++;
		}
	}
	cout << res << "/" << (n * (n - 1)) / 2;
}
