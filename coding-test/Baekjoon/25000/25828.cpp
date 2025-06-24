#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int g, p, t;
    cin >> g >> p >> t;

    if (g + p * t > g * p)
        cout << 1;
    else if (g + p * t < g * p)
        cout << 2;
    else
        cout << 0;
}
