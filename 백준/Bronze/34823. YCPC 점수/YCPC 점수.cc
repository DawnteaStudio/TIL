#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int y, c, p;
	cin >> y >> c >> p;
	cout << min(min(y, (c / 2)), p);
}
