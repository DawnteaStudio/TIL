#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, c;
    cin >> a >> b >> c;
    if (a * b > c)
        cout << a * b - c;
    else
        cout << 0;
}
