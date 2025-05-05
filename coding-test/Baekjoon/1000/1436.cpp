#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, res = 0, tmp = 666, len, cnt, num;
    bool ok;
    cin >> n;
    while (n > res)
    {
        string str = to_string(tmp);
        len = str.length();
        ok = false;
        for (int i = 0; i < len; i++)
        {
            cnt = 0;
            while (i < len && str[i] == '6')
            {
                i++;
                cnt++;
            }
            if (cnt >= 3)
            {
                ok = true;
                num = tmp;
                break;
            }
        }
        if (ok)
            res++;
        tmp++;
    }
    cout << num;
}
