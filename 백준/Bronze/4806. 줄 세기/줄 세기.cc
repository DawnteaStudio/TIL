#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int cnt = 0;
	string str;

	while (true) {
		if (getline(cin, str))
			cnt++;
		else
			break;
	}
	cout << cnt;
}
