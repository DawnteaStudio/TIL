#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str, s, rev, t, rev_t;
    int n, len;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        len = str.length();
        if (len % 3 == 0)
            len = len / 3;
        else
            len = len / 3 + 1;
        s = str.substr(0, len);
        rev = s;
        reverse(rev.begin(), rev.end());
        t = s.substr(1);
        rev_t = rev.substr(1);
        if (str == s + rev + s || str == s + rev_t + s || str == s + rev + t || str == s + rev_t + t)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}
