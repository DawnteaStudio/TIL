#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    comp(string a, string b)
{
    int i = 0;
    if (a.length() > b.length())
        return false;
    else if (a.length() == b.length())
    {
        while (i < a.length())
        {
            if (a[i] > b[i])
                return false;
            else if (a[i] < b[i])
                return true;
            else
                i++;
        }
    }
    return true;
}

int main()
{
    fast;
    int n;
    string str, tmp;
    stack<string> s;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        tmp = "";
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] >= '0' && str[j] <= '9')
                tmp += str[j];
            else if (tmp.length() > 0)
            {
                int idx = 0;
                if (tmp[0] != '0')
                    s.push(tmp);
                else if (tmp[0] == '0')
                {
                    while (tmp[idx] == '0')
                        idx++;
                    if (idx == tmp.length())
                        tmp = "0";
                    else
                        tmp = tmp.substr(idx);
                    s.push(tmp);
                }
                tmp = "";
            }
        }
        if (tmp.length() > 0)
        {
                int idx = 0;
                if (tmp[0] != '0')
                    s.push(tmp);
                else if (tmp[0] == '0')
                {
                    while (tmp[idx] == '0')
                        idx++;
                    if (idx == tmp.length())
                        tmp = "0";
                    else
                        tmp = tmp.substr(idx);
                    s.push(tmp);
                }
                tmp = "";
        }
    }
    int size = s.size();
    string arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = s.top();
        s.pop();
    }
    sort(arr, arr + size, comp);
    for (int i = 0; i < size; i++)
        cout << arr[i] << '\n';
}
