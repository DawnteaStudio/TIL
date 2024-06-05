#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, c;
	cin >> a >> b >> c;

	if (a >= 1000)
	{
		if (b >= 8000 || c >= 260)
			cout << "Very Good";
		else
			cout << "Good";
	}
	else
		cout << "Bad";
}