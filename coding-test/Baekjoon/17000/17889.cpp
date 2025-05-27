#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;

	int cnt = 2;
	int year = 2018;
	while (year < n) {
		year += 2;
		cnt += 2;
		if (cnt == 12) {
			year++;
			cnt = 0;
		}
	}
	if (year == n)
		cout << "yes";
	else
		cout << "no";
}