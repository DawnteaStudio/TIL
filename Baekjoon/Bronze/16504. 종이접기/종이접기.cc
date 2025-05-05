#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	long long n, tmp;
	cin >> n;
	long long res = 0;
	for (long long i = 0; i < n * n; i++)
	{
		cin >> tmp;
		res += tmp;
	}
	cout << res;
}
