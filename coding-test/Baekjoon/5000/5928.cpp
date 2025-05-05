#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int d, h, m;
    cin >> d >> h >> m;

    int t = 11 * 24 * 60 + 11 * 60 + 11;
    int my_t = d * 24 * 60 + h * 60 + m;
    if (t > my_t)
        cout << -1;
    else
        cout << my_t - t;
}