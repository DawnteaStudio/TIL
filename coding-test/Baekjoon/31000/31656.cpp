#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    string str;
    char tmp = 0;
    getline(cin, str);

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] != tmp)
            cout << str[i];
        tmp = str[i];
    }
}
