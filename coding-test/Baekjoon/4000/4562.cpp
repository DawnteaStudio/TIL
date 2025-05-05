#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    int a, b;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a < b)
            cout << "NO BRAINS\n";
        else
            cout << "MMM BRAINS\n";
    }
}