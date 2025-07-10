#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<int> v(10, 0);
	int len = str.length();

	for (int i = 0; i < len; i++) {
		v[str[i] - '0']++;
	}
	int res = 0;
	v[6] += v[9];
	v[9] = 0;
	if (v[6] % 2 != 0)
		v[6]++;
	v[6] /= 2;
	for (int i = 0; i < 10; i++) {
		if (v[i] > res)
			res = v[i];
	}
	cout << res;
}
