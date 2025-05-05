#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int height, width, res;

    cin >> height >> width;
    if (height < 3)
    {
        if (height == 1)
            cout << 1;
        else if (width > 6)
            cout << 4;
        else if (width > 4)
            cout << 3;
        else if (width > 2)
            cout << 2;
        else
            cout << 1;
    }
    else if (width >= 7)
        cout << width - 2;
    else if (width >= 4)
        cout << 4;
    else
        cout << width;
}
