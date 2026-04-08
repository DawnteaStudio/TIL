#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	long long a, b;
    cin >> a >> b;

    long long x = a * 10;

    if (x < b * 2) {
        cout << "weak";
    } else if (x < b * 4) {
        cout << "normal";
    } else if (x < b * 6) {
        cout << "strong";
    } else {
        cout << "very strong";
    }
}
