#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n;
	cin >> n;

	cout << (int)((n * n) / 4 + 0.5);
}