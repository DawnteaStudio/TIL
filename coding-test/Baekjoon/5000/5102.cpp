#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
            break ;
		int tmp = a - b;
		if (tmp % 2 == 0)
            cout << tmp / 2 << " 0\n";
		else if (tmp - 3 >= 0)
            cout << (tmp - 3) / 2 << " 1\n";
		else
            cout << "0 0\n";
	}
}