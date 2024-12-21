#include <iostream>
#include <vector>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long cnt, res;

int main() {
	fast;
	int n, res_v;
	cin >> n;

	long long tmp;
	vector<pair<long long, long long> > vec;
	map<long long, long long> tuition;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tuition.find(tmp) == tuition.end())
			tuition[tmp] = 1;
		else
			tuition[tmp]++;
	}

	for (map<long long, long long>::iterator iter = tuition.begin(); iter != tuition.end(); iter++)
		vec.push_back(make_pair(iter->first, iter->second));
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		cnt += vec[i].second;
		if (cnt * vec[i].first >= res)
		{
			res = cnt * vec[i].first;
			res_v = vec[i].first;
		}
	}
	cout << res << " " << res_v;
}
