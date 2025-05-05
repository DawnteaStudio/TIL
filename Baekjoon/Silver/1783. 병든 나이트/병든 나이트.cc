#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, M;
    cin >> N >> M;

    if (N < 3)
    {
        if (N == 2)
        {
            if (M >= 7)
                cout << 4;
            else if (M >= 5)
                cout << 3;
            else if (M >= 3)
                cout << 2;
            else
                cout << 1;
        }
        else
            cout << 1;
        return (0);
    }
    if (N >= 3)
    {
        if (M >= 7)
            cout << M - 2;
        else if (M >= 4)
            cout << 4;
        else if (M >= 3)
            cout << 3;
        else if (M >= 2)
            cout << 2;
        else
            cout << 1;
    }
}