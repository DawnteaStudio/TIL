#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    int n;
	cin >> n;

	string str;
	cin >> str;

	for (int i = 0; i <= n - 4; i++) {
		if (str.substr(i, 4) == "gori") {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
