#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    bool m = false, o = false, b = false, ii = false, s = false;

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'M')
            m = true;
        else if (str[i] == 'O')
            o = true;
        else if (str[i] == 'B')
            b = true;
        else if (str[i] == 'I')
            ii = true;
        else if (str[i] == 'S')
            s = true;
    }
    if (m == true && o == true && b == true && ii == true && s == true)
        cout << "YES";
    else
        cout << "NO";
}
