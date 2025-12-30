#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int m = -1, total = 0, tmp;
	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		if (tmp > m)
			m = tmp;
		total += tmp;
	}

	if (total == m * 2)
		cout << 1;
	else
		cout << 0;
}