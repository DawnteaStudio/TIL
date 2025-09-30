#include <iostream>
#include <cmath>
#include <iomanip>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	long long n;
	cin >> n;

	double len = sqrt(n);
	cout << fixed << setprecision(6);
	cout << len * 4;
}
