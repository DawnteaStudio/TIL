#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    if (n == 1 || n == 3)
    {
        cin >> n;
        if (n == 6 || n == 8)
        {
            cin >> n;
            if (n == 2 || n == 5)
                cout << "JAH";
            else
                cout << "EI";
        }
        else
            cout << "EI";
    }
    else
        cout << "EI";
}
