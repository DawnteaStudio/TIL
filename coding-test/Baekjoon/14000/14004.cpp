#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (c + d) / (a - b);
}