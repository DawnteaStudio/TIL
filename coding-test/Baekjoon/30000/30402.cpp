#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    char c;
    for (int i = 0; i < 225; i++)
    {
        cin >> c;
        if (c == 'w')
        {
            cout << "chunbae";
            break;
        }
        else if (c == 'b')
        {
            cout << "nabi";
            break;
        }
        else if (c == 'g')
        {
            cout << "yeongcheol";
            break;
        }
    }
}