#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int n;
	string s;
	cin >> n >> s;

	if (s == "miss")
		cout << 0;
	else if (s == "bad")
		cout << 200 * n;
	else if (s == "cool")
		cout << 400 * n;
	else if (s == "great")
		cout << 600 * n;
	else
		cout << n * 1000;
}
