#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int l, r, b;
    cin >> l >> r >> b;
    while (b != 0 && l != r)
    {
        if (l < r)
            l++;
        else
            r++;
        b--;
    }
    cout << min(l, r) * 2 + (b - (b % 2));
}