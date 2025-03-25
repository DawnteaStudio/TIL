#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

#define EPS 1e-9
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

string format_num(double x) {
    if (abs(x - round(x)) < EPS) {
        return to_string(int(round(x)));
    }
    stringstream ss;
    ss << fixed << setprecision(8) << x;
    string s = ss.str();
    while (!s.empty() && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();
    return s.empty() ? "0" : s;
}

pair<double, double> cartesian_to_polar(double x, double y) {
    if (abs(x) < EPS && abs(y) < EPS) return {0.0, 0.0};
    double r = hypot(x, y);
    double theta = atan2(y, x);
    if (theta < 0) theta += 2 * M_PI;
    return {r, theta};
}

pair<double, double> polar_to_cartesian(double r, double theta) {
    if (abs(r) < EPS) return {0.0, 0.0};
    double x = r * cos(theta);
    double y = r * sin(theta);
    return {x, y};
}

int main() {
    fast;
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        int coord_type;
        double a, b;
        cin >> coord_type >> a >> b;

        if (coord_type == 1) {
            auto [r, theta] = cartesian_to_polar(a, b);
            cout << format_num(r) << " " << format_num(theta) << "\n";
        } 
        else if (coord_type == 2) {
            auto [x, y] = polar_to_cartesian(a, b);
            cout << format_num(x) << " " << format_num(y) << "\n";
        }
    }

    return 0;
}
