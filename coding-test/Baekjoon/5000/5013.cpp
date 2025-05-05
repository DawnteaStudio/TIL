#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, cnt = 0;
    bool flag;
    cin >> n;
    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        flag = true;
        for (int j = 0; j < (int)str.length() - 1; j++)
        {
            if (str[j] == 'C')
            {
                if (str[j + 1] == 'D')
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cnt++;
    }
    cout << cnt;
}