#include <iostream>
#include <iomanip>
#include <algorithm>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    fast;
    
    double r, g, b, r1, g1, b1;
    cin >> r >> g >> b;

    r1 = r / 255.0;
    g1 = g / 255.0;
    b1 = b / 255.0;

    double k = 1.0 - max({r1, g1, b1});

    cout << fixed << setprecision(4);

    if (k == 1.0) {
        cout << 0.0 << " " << 0.0 << " " << 0.0 << " " << 1.0;
    } else {
        cout << (1.0 - r1 - k) / (1.0 - k) << " ";
        cout << (1.0 - g1 - k) / (1.0 - k) << " ";
        cout << (1.0 - b1 - k) / (1.0 - k) << " ";
        cout << k;
    }
}