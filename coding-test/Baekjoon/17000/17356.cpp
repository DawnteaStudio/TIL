#include <iostream>
#include <cmath>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int a, b;
    cin >> a >> b;

    double m = (b - a) / 400.0;
    double res= 1 / (1 + pow(10, m));
    cout << res;
}