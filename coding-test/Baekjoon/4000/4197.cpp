#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

const double pi = 3.14159265358979;

int main() {
    fast;

    int t, cnt, d;
    string cmd;
    cin >> t;
    double y, x, rad;
    int degree;
    cout << fixed;
    cout << setprecision(3);

    for (int i = 0; i < t; i++) {
        cin >> cnt;
        y = 0, x = 0, degree = 0, rad = 0;
        
        for (int j = 0; j < cnt; j++) {
            cin >> cmd >> d;
            if (cmd == "lt") {
                degree += d;
                degree %= 360;
                rad = degree * pi / 180.0;
            }
            else if (cmd == "rt") {
                degree = (degree - d + 360) % 360;
                rad = degree * pi / 180.0;
            }
            else if (cmd == "bk") {
                y -= d * cos(rad);
                x -= d * sin(rad);
            }
            else {
                y += d * cos(rad);
                x += d * sin(rad);
            }
        }
        cout << llroundl(sqrt(y * y + x * x)) << '\n';
    }
}
