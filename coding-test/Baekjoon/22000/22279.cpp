#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n; cin >> n;
    cout.precision(3);
    cout << fixed;

    double qaly=0, q, y;
    for (int i=0; i<n; i++) {
        cin >> q >> y;
        qaly += q * y;
    }
    cout << qaly;
    return (0);
}