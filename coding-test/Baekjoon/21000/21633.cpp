#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    cout << fixed;
    cout.precision(2);
    double res = 25;
    res += n * 0.01;
    if (res < 100)
        cout << "100.00\n";
    else if (res > 2000)
        cout << "2000.00\n";
    else
        cout << res << '\n';
}
