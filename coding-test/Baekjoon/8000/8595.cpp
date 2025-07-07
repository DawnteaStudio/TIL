#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    long long res = 0, len;
    string s;
    cin >> len >> s;

    long long tmp = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            tmp = tmp * 10 + s[i] - '0';
        }
        else
        {
            res += tmp;
            tmp = 0;
        }
    }
    cout << res + tmp;
}