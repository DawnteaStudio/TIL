#include <iostream>
#include <iomanip>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    double dollar = 100;
    double cur, pre = 0;
    cin >> n;

    cout.precision(2);
    cout << fixed;

    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (pre > cur)
            dollar *= (pre / cur);
        pre = cur;
    }

    cout << dollar;
}

