#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, a, b, c, total, max_total=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        if (a == b && b == c) total = 10000 + a * 1000;
        else if (a == b || a == c) total = 1000 + a * 100;
        else if (b == c) total = 1000 + b * 100;
        else total = 100 * max(max(a, b), c);
        max_total = max(max_total, total); 
    }
    cout << max_total;
}