#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t;
	while (true) {
		cin >> t;
		if (t == 0) break ;
		int m = 0, j = 0, r;
		for (int i=0; i<t; i++) {
			cin >> r;
			if (r == 0) m++;
			else j++;
		}
		cout << "Mary won " << m << " times and John won " << j << " times\n";
	}
	return (0);
}
