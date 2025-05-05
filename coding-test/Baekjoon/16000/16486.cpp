#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define PI 3.141592

int main()
{
    fast;
    double a, b;
    cin >> a >> b;

    cout << fixed;
    cout.precision(6);
    cout << 2 * a + 2 * PI * b;
}
