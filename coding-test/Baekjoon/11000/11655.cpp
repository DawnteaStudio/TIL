#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (true);
    return (false);
}

int main()
{
    fast;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (is_alpha(str[i]))
        {
            if (str[i] < 'A' + 13 || str[i] >= 'a' && str[i] < 'a' + 13)
                cout << (char)(str[i] + 13);
            else
                cout << (char)(str[i] - 13);
        }
        else
            cout << str[i];
    }
}
