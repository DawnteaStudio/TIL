#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main()
{
	fast;
	int n, res = 0, tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		res += tmp;
	}
	cin >> n;
	if (n * 4 < res)
		cout << 0;
	else
		cout << n * 4 - res;
}