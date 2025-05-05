#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
        cout << "Not a moose";
    else if (n == m)
        cout << "Even " << n * 2;
    else
        cout << "Odd " <<  max(n, m) * 2;
}
