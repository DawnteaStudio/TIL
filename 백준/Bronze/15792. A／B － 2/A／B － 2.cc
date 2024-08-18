#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int a, b, res;
	cin >> a >> b;
	cout << (int)(a/b) << ".";
	a %= b;
	for (int i = 0; i < 1000; i++)
	{
		a *= 10;
		cout << a/b;
		a = a - (a/b)*b;
	}
}
