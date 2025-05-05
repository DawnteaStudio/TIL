#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t;
    cin >> t;
    int n , k;
    long long ans;
    for (int i = 1; i <= t; i++) {
        cin >> n >> k;
        ans = pow(2, n);
        if (k == 0)
            cout << "Case #" << i << ": OFF\n";
        else if (ans > k + 1)
            cout << "Case #" << i << ": OFF\n";
        else if ((k + 1) % ans == 0)
            cout << "Case #" << i << ": ON\n";
        else
            cout << "Case #" << i << ": OFF\n";
    }
}
