#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int len;
    string str;
    bool flag = true;
    cin >> len;
    cin >> str;
    if (len <= 25)
        cout << str;
    else
    {
        vector<string> lines;
        int pos = 0;
        for (int i = 0; i < len;)
        {
            pos = str.find('.', i);
            lines.push_back(str.substr(i, pos - i + 1));
            i = pos + 1;
        }
        string mid = str.substr(11, len - 22);
        int cnt = lines.size();
        for (int i = 0; i < cnt; i++)
        {
            if (lines[i].find(mid) != string::npos)
            {
                cout << str.substr(0, 11) + "..." + str.substr(len - 11);
                flag = false;
                break;
            }
        }
        if (flag)
            cout << str.substr(0, 9) + "......" + str.substr(len - 10);
    }
}
