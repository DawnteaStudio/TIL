#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    
    int n;
    cin >> n;
    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << 7;
    else if (n == 3)
        cout << 2;
    else
        cout << 3;
}