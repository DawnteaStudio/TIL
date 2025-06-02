#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == 8 || a == 9) {
		if (d == 8 || d == 9) {
			if (b == c)
				cout << "ignore";
			else
				cout << "answer";
		}
		else
			cout << "answer";
	}
	else
		cout << "answer";

}
