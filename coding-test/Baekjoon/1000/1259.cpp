#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str;
    string tmp;
    while(true)
    {
        cin >> str;
        tmp = str;
        if (str == "0")
            break;
        reverse(str.begin(), str.end());
        if (str == tmp)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}