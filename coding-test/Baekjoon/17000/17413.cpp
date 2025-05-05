#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str, res;
    int start_i = 0, end_i = 0, tmp;

    getline(cin, str);
    res = str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '<')
        {
            start_i = i;
            while (str[i] != ' ' && str[i] != '<' && i < str.length())
                i++;
            i--;
            end_i = i;
            tmp = start_i;
            while (end_i >= start_i)
            {
                res[tmp] = str[end_i];
                tmp++;
                end_i--;
            }
        }
        else if (str[i] == ' ')
            continue;
        else
            while (str[i] != '>')
                i++;
    }
    cout << res;
}
