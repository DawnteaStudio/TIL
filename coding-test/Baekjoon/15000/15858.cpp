#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long q1 = a / c;
    long long r1 = a % c;

    long long int_part = q1 * b + (r1 * b) / c;
    long long rem = (r1 * b) % c;

    long long frac_part = (rem * 1000000) / c;

    cout << int_part << "."
        << setw(6) << setfill('0') << frac_part << endl;
}