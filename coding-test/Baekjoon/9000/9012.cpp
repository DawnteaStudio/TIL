#include <iostream>
#include <stack>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, flag;
    string str;
    stack<char> s;

    cin >> n;
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        flag = 0;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '(')
                s.push('(');
            else if (s.empty())
            {
                flag = 1;
                break;
            }
            else
                s.pop();
        }
        if (s.empty() && flag == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
        while (!s.empty())
            s.pop();
    }
}