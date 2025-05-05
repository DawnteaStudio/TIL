#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 0; j < (2 * n - 1) - 2 * i; j++)
			cout << '*';
		cout << '\n';
	}
}