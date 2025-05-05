#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, res = 0;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());

	int member = 0, member_min = vec[0];
	for (int i = 0; i < n; i++)
	{
		if (member_min == 0)
			member_min = vec[i];
		if (member < member_min)
			member++;
		if (member == member_min)
		{
			res++;
			member = 0;
			member_min = 0;
		}
	}
	if (member != 0)
		res++;
	cout << res;
}
