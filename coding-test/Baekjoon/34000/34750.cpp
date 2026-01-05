#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n;
	cin >> n;

	if (n >= 1000000)
		cout << n * 20 / 100 << " " << n * 80 / 100; 
	else if (n >= 500000)
		cout << n * 15 / 100 << " " <<  n * 85 / 100;
	else if (n >= 100000)
		cout << n * 10 / 100 << " " <<  n * 90 / 100;
	else
		cout << n * 5 / 100 << " " <<  n * 95 / 100;
}