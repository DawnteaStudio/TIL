#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str = "WelcomeToSMUPC";
    int len = str.length(), input;
    cin >> input;
    while (input > len)
        input -= len;
    if (input == len)
        cout << str[13];
    else
        cout << str[(input % len) - 1];
}
