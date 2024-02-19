#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    is_increase(int b, int c, int d)
{
    if (b < c && c < d)
        cout << "Fish Rising";
    else
        cout << "No Fish";
}

void    is_all_same(int b, int c, int d)
{
    if (b == c && c == d)
        cout << "Fish At Constant Depth";
    else
        cout << "No Fish";
}

void    is_decrease(int b, int c, int d)
{
    if (b > c && c > d)
        cout << "Fish Diving";
    else
        cout << "No Fish";
}

int main()
{
    fast;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b)
        is_increase(b, c, d);
    else if (a == b)
        is_all_same(b, c, d);    
    else
        is_decrease(b, c, d);
}
