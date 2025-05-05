#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int prefix_sum(string str, int start, int end)
{
    int res = 0;

    for(int i = start; i < end; i++)
        res += str[i] - '0';
    return (res);
}

int main()
{
    fast;
    string str;
    cin >> str;

    int len = str.length();
    int res = (len / 2) * 2;
    while (res > 0)
    {
        for (int i = 0; i <= len - res; i++)
        {
            if (prefix_sum(str, i, i + (res / 2)) == prefix_sum(str, i + (res / 2), i + res))
            {
                cout << res;
                return(0);
            }
        }
        res -= 2;
    }
    cout << 0;
}
