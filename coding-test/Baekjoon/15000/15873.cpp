#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str;
    cin >> str;

    if (str.length() == 4)
        cout << stoi(str.substr(0, 2)) + stoi(str.substr(2, 2));
    else if (str.length() == 3)
    {
        if (str[1] == '0')
            cout << stoi(str.substr(0, 2)) + stoi(str.substr(2));
        else
            cout << stoi(str.substr(0, 1)) + stoi(str.substr(1, 2));
    }
    else
        cout << (str[0] - '0') + (str[1] - '0');
}