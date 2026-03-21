#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n;
	cin >> n;
	int cost = 900 + 60 + 600 + 170 + 160 + 110;
	cout << n / cost;
}
