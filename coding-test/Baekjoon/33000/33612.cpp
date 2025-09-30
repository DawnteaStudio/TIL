#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n; cin >> n;

	int month = 8 + (n - 1) * 7, year = 2024;
	while (month > 12) {
		year++;
		month -= 12;
	}
	cout << year << " " << month;
}
