#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a;
    cin >> a;
    cout << fixed;
    cout.precision(3);
    double first = (double)a * 0.01, second = (double)(100 - a) * 0.01;
    cout << 1.0 / first << '\n';
    cout << 1.0 / second << '\n';
}