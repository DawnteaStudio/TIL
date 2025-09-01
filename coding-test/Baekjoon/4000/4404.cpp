#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    double dx, dy, dogx, dogy;
    cin >> dx >> dy >> dogx >> dogy;

    cout << fixed;
    cout.precision(3);
    double x, y;
    while (cin >> x) {
        cin >> y;
        double a = (dx - x) * (dx - x) + (dy - y) * (dy - y);
        double b = (dogx - x) * (dogx - x) + (dogy - y) * (dogy - y);

        if (4 * a < b) {
            cout << "The gopher can escape through the hole at (" << x << "," << y << ").";
            return 0;
        } 
    }
    cout << "The gopher cannot escape.";
}
