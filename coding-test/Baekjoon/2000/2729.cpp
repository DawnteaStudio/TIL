#include <iostream>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, alen, blen;
    char achar, bchar;
    bool up;
    cin >> n;

    string a, b, res;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        up = false;
        res = "";
        reverse(a.rbegin(), a.rend());
        reverse(b.rbegin(), b.rend());

        alen = a.length();
        blen = b.length();
        int len = max(alen, blen);
        for (int j = 0; j < len; j++)
        {
            if (alen <= j)
                achar = '0';
            else
                achar = a[j];
            if (blen <= j)
                bchar = '0';
            else
                bchar = b[j];
            if (achar + bchar == '0' + '0')
            {
                if (up)
                    res += "1";
                else
                    res += "0";
                up = false;
            }
            else if (achar + bchar == '0' + '1')
            {
                if (up)
                    res += "0";
                else
                {
                    res += "1";
                    up = false;
                }
            }
            else
            {
                if (up)
                    res += "1";
                else
                    res += "0";
                up = true;
            }
        }
        if (up)
            res += "1";
        reverse(res.begin(), res.end());
        bool isZero = true;
        for (int k = 0; k < res.length(); k++)
        {
            if (isZero && res[k] == '0')
                continue;
            else
                isZero = false;
            cout << res[k];
        }
        if (isZero)
            cout << "0";
        cout << '\n';
    }
}
