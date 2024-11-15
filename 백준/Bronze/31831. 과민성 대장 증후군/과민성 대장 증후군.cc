#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, m, res = 0, sum = 0;
	cin >> n >> m;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		sum += tmp;
		if (sum < 0)
			sum = 0;
		if (sum >= m)
			res++;
	}
	cout << res;
}
