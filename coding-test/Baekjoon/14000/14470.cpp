#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int time = 0;

    if (a < 0) time = -a * c + d + e * b;
    else if (a == 0) time = d + e * b;
    else time = e * (b - a);
    
    cout << time << '\n';
}
