#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int h, l, a, b;
    cin >> h >> l >> a >> b;
    h *= 2;

    if (h >= a && l >= b)
        cout << "YES";
    else if (h >= b && l >= a)
        cout << "YES";
    else
        cout << "NO";
}