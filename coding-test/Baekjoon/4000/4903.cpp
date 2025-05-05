#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        if (a == 1 || b == 1)
            cout << a << "+" << b << "=" << a + b << endl;
        else
            cout << a << "+" << b << "!=" << a + b << endl;
        
    }
    
}
