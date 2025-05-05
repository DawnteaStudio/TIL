#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check(double xi, double xj, double li, double lj)
{
    return (abs(xi - xj) <= (li + lj));
}

int main()
{
    fast;
    int n; cin >> n;

    double x[n], l[n];
    char c[n];
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) cin >> l[i];
    for (int i=0; i<n; i++) cin >> c[i];

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (check(x[i], x[j], l[i], l[j]) && c[i] != c[j]) {
                cout << "YES\n";
                cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}