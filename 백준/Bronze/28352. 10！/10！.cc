#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	cin >> n;
	long long v = 1;
	for (int i = 1; i <= n; i++)
		v *= i;
	
	long long res = 7 * 24 * 60 * 60;
	for (int i = 1;; i++)
	{
		if (res * i == v)
		{
			cout << i;
			break;
		}
	}
}