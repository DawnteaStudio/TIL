#include <iostream>
#include <queue>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    swap(int pos_p, int pos_c, string &res)
{
    char tmp = res[pos_p];
    res[pos_p] = res[pos_c];
    res[pos_c] = tmp;
    pos_p = -1;
    pos_c = -1;
}

int main() {
    fast;
    int n;
    queue<int> pos_p, pos_c;
    string str, res;
    cin >> n >> str;

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        res += str[i];
        if (str[i] == 'P')
        {
            pos_p.push(i);
            if (!pos_c.empty())
            {
                swap(pos_p.front(), pos_c.front(), res);
                pos_p.pop();
                pos_c.pop();
            }
        }
        else if (str[i] == 'C')
        {
            pos_c.push(i);
            if (!pos_p.empty())
            {
                swap(pos_p.front(), pos_c.front(), res);
                pos_p.pop();
                pos_c.pop();
            }
        }
    }
    cout << res;
}
