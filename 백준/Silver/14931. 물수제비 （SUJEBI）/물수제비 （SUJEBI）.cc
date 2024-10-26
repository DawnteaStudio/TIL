#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int l;
	long long res = 0;
	cin >> l;
	vector<int> vec(l + 1);
	int index = 1;
	for (int i = 1; i <= l; i++)
	{
		cin >> vec[i];
		res += vec[i];
	}

	for (int d = 2; d <= l; d++)
	{
		long long tmp = 0;
		for (int i = d; i <= l; i += d)
			tmp += vec[i];
		if (tmp > res)
		{
			index = d;
			res = tmp;
		}
	}
	if (res > 0)
		cout << index << " " << res;
	else
		cout << 0 << " " << 0;
}