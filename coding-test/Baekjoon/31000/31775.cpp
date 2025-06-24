#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string input;
    int k = 0, l = 0, p = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> input;
        if (input[0] == 'k')
            k = 1;
        if (input[0] == 'l')
            l = 1;
        if (input[0] == 'p')
            p = 1;
    }
    if (k * l * p == 1)
        cout << "GLOBAL";
    else
        cout << "PONIX";
}
