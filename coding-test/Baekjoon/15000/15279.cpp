#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    double b, p;
    cin >> n;
    cout.precision(4);
    cout << fixed;
    for (int i = 0; i < n; i++)
    {
        cin >> b >> p;
        cout << 60 / p * (b - 1) << " " << 60 * b / p << " " << 60 / p * (b + 1);
        cout << '\n';
    }
}