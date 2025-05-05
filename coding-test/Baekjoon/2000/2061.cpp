#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    div_big_num(string str, int l)
{
    int value = 0;
    int mod;
    for (int i = 0; i < str.length(); i++)
    {
        value = value * 10 + str[i] - '0';
        if (value < l)
        {
            mod = value;
            continue;
        }
        mod = value % l;
        value = mod;
    }
    if (mod == 0)
        return false;
    else
        return true;
}

int main()
{
    fast;
    string k;
    int l, t = 2;
    cin >> k >> l;

    while (t < l)
    {
        if (div_big_num(k, t) == false)
        {
            cout << "BAD " << t;
            return (0);
        }
        t++;
    }
    cout << "GOOD";
}
