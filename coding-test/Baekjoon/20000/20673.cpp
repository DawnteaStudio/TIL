#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    if (n <= 50 && m <= 10)
        cout << "White";
    else if (m > 30)
        cout << "Red";
    else
        cout << "Yellow";
}
