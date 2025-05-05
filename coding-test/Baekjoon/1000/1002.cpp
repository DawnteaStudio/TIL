#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double dist = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
        if (x1 == x2 && y1 == y2 && r1 == r2)
            cout << -1 << '\n';
        else if (r1 + r2 == dist)
            cout << 1 << '\n';
        else if (r1 + r2 < dist)
            cout << 0 << '\n';
        else
        {
            if (abs(r1 - r2) == dist)
                cout << 1 << '\n';
            else if (abs(r1 - r2) < dist)
                cout << 2 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}