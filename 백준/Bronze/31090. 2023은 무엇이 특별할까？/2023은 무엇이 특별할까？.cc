#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, num, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> num;
		n = num + 1;
		num %= 100;
		if (n % num == 0)
			cout << "Good\n";
		else
			cout << "Bye\n";
	}
}