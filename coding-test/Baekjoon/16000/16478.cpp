#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    double ab, bc, cd;
    cin >> ab >> bc >> cd;
    cout.precision(6);
    cout << fixed;
    cout << (ab * cd) / bc;
}
