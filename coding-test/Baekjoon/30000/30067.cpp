#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int total = 0, tmp;
	for (int i = 0; i < 10; i++) {
		cin >> tmp;
		total += tmp;
	}
	cout << total / 2;
}