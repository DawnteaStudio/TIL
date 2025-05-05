#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    click(int index, string &str)
{
    int add = index + 1;
    for (int i = index; i < str.length(); i += add)
    {
        if (str[i] == 'Y')
            str[i] = 'N';
        else
            str[i] = 'Y';
    }
}

int main()
{
    fast;
    string light;
    int res = 0;
    cin >> light;

    for (int i = 0; i < light.length(); i++)
    {
        if (light[i] == 'Y')
        {
            click(i, light);
            res++;
        }
    }
    cout << res;
}