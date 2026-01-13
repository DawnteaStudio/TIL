#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << n / 2;
	else
		cout << n / 2 + 3;
}
