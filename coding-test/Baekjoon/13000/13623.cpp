#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
        cout << "*";
    else if (a == b)
        cout << "C";
    else if (a == c)
        cout << "B";
    else
        cout << "A";
}
