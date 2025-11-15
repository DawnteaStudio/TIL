#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    long long n;
	cin >> n;

	if (n >= -32768 && n <= 32767)
		cout << "short";
	else if (n >= -2147483648 && n <= 2147483647)
		cout << "int";
	else
		cout << "long long";
}
