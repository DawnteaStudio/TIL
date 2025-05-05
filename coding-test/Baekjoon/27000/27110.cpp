#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    if (a > n)
        a = n;
    if (b > n)
        b = n;
    if (c > n)
        c = n;
    cout << a + b + c;
}