#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, res = 0;
    cin >> n >> m;
    if (n >= 2 * m)
        cout << m;
    else
        cout << (n / 2);
}