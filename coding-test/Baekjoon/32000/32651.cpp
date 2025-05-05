#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    if (n > 100000)
        cout << "No";
    else
    {
        if (n % 2024 == 0)
            cout << "Yes";
        else
            cout << "No";
    }
}