#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, tmp;
	cin >> a >> b;

	int res = a * b;
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		cout << tmp - res << ' ';
	}
}