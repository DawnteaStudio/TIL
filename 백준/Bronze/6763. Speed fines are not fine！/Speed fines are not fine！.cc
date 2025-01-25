#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int l, s;
	cin >> l >> s;
	if (s - l > 30)
		cout << "You are speeding and your fine is $500.";
	else if (s - l > 20)
		cout << "You are speeding and your fine is $270.";
	else if (s - l > 0)
		cout << "You are speeding and your fine is $100.";
	else
		cout << "Congratulations, you are within the speed limit!";
}