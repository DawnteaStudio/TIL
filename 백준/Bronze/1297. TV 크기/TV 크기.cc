#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int d, h, w;
	cin >> d >> h >> w;

	double a = d * d;
	a /= h * h + w * w;
	a = sqrt(a);

	h *= a;
	w *= a;
	cout << h << " " << w;
}
