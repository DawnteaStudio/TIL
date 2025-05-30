#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string add_string(string &a, string &b)
{
    string tmp_a = a;
    string tmp_b = b;
    string long_str;
    string res;
    reverse(tmp_a.begin(), tmp_a.end());
    reverse(tmp_b.begin(), tmp_b.end());

    int len_a = a.length();
    int len_b = b.length();
    int up = 0;
    int len = len_a > len_b ? len_b : len_a;
    int l_len = len_a > len_b ? len_a : len_b;
    long_str = len_a > len_b ? tmp_a : tmp_b;

    for (int i = 0; i < l_len; i++)
    {
        if (i < len)
        {
            int num_a = tmp_a[i] - '0';
            int num_b = tmp_b[i] - '0';
            int num = 0 + up;

            num += (num_a + num_b);
            if (num >= 10)
            {
                up = 1;
                num -= 10;
            }
            else
            {
                up = 0;
            }

            res += (char)(num + '0');
        }
        else
        {
            int num = up + long_str[i] - '0';
            if (num > 10) {
                up = 1;
                num -= 10;
            }
            else {
                up = 0;
            }
            res += (char)(num + '0');
        }
    }
    if (up)
        res += "1";
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    fast;
    vector<string> dp(491);
    dp[1] = "1";
    dp[2] = "1";

    for (int i = 3; i <= 490; i++)
        dp[i] = add_string(dp[i - 1], dp[i - 2]);

    int n;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        cout << "Hour " << n << ": " << dp[n] << " cow(s) affected\n";
    }
}