#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << '\n';
    if (b / 10 >= 100)
        a *= 10000;
    else if (b / 10 >= 10)
        a *= 1000;
    else if (b / 10 >= 1)
        a *= 100;
    else
        a *= 10;
    cout << a + b - c;
}