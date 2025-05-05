#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str;
    getline(cin, str);

    if (str.length() > 2 && str[0] == '\"' && str[str.length() - 1] == '\"')
        cout << str.substr(1, str.length() - 2);
    else
        cout << "CE";
}
