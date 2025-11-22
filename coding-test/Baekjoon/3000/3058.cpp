#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t;
	cin >> t;

	int s, total;
	for (int i = 0; i < t; i++) {
		s = 101;
		total = 0;
		for (int j = 0; j < 7; j++) {
			int tmp;
			cin >> tmp;
			if (tmp % 2 == 0) {
				if (tmp < s)
					s = tmp;
				total += tmp;
			}
		}
		cout << total << " " << s << '\n';
	}
}
