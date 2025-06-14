#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str;
    cin >> str;
    int res = 0, yres = 0;

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            res++;
        if (str[i] == 'y')
            yres++;
    }
    cout << res << " " << res + yres;
}
