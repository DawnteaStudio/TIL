#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
    fast;
    int m, n, cnt = 0, len;
    bool odd;
    string s, cmp;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        s = to_string(i);
        cmp = s;
        reverse(cmp.begin(), cmp.end());
        len = s.length();
        odd = len % 2;
        for (int j = 0; j < len; j++)
        {
            if (s[j] == '0' || s[j] == '1' || s[j] == '8')
            {
                if (s[j] != cmp[j])
                    break;
            }
            else if (s[j] == '6' || s[j] == '9')
            {
                if (s[j] + cmp[j] != '6' + '9' || (odd && j * 2 + 1 == len))
                    break;
            }
            else
                break;
            if (j == len - 1)
                cnt++;
        }
    }
    cout << cnt;
}
