#include <iostream>
#include <string>
using namespace std;

void turn(string &str)
{
    int deg = 0;
    int len = str.length();

    for (int i = 0; i < len; i++)
        deg += str[i] - 'A';
    deg %= 26;

    for (int i = 0; i < len; i++)
        str[i] = 'A' + ((str[i] + deg) % 'A') % 26;
}

int main()
{
    string str;
    cin >> str;

    string a, b;
    int len = str.length();
    a = str.substr(0, len/2);
    b = str.substr(len/2);
    turn(a);
    turn(b);

    for (int i = 0; i < len/2; i++) {
        cout << (char)('A' + ((a[i] + (b[i] -'A')) % 'A') % 26);
    }
}
