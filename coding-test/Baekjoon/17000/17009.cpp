#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a = 0, b = 0, input;
    for (int i = 0; i < 3; i++)
    {
        cin >> input;
        if (i == 0)
            a += input * 3;
        else if (i == 1)
            a += input * 2;
        else
            a += input;
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> input;
        if (i == 0)
            b += input * 3;
        else if (i == 1)
            b += input * 2;
        else
            b += input;
    }

    if (a > b)
        cout << "A";
    else if (a < b)
        cout << "B";
    else
        cout << "T";
}
