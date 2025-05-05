#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b;
    cin >> a >> b;

    while (a <= b)
    {
        cout << "All positions change in year " << a << '\n';
        a += 60;
    }
    return (0);
}