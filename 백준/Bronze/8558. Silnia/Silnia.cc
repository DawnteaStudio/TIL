#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a <= 1)
        cout << 1;
    else if (a == 2)
        cout << 2;
    else if (a == 3)
        cout << 6;
    else if (a == 4)
        cout << 4;
    else
        cout << 0;
}
