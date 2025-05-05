#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    double w, h; cin >> w >> h;
    cout.precision(6);
    cout << fixed;
    cout << w + h - sqrt(w * w + h * h);
    return 0;
}