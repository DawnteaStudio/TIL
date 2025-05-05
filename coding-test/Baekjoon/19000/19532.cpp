#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

int main()
{
    fast;
    int a,b,c,d,e,f,x,y;
    cin >> a >> b >> c >> d >> e >> f;

    y = (c*d - a*f)  / (d*b - a*e);
    if (a != 0)
        x = (c - b*y) / a;
    else
        x = (f - e * y) / d;

    cout << x << ' ' << y;
}