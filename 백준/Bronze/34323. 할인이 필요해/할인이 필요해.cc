#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	long long n, m, s;
    cin >> n >> m >> s;
	double discount = (m + 1) * s * (100 - n) / 100.0;
	cout << min(s * m, (long long)discount);
}