#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str, tmp_s, res;
    while (true) {
        cin >> str;
        if (str == "E-N-D")
            break;
        int len = str.length();
        int tmp = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == '-' || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                tmp++;
                tmp_s += str[i];
            }
            else {
                if (res.length() < tmp_s.length())
                    res = tmp_s;
                tmp_s = "";
                tmp = 0;
            }
        }
        if (res.length() < tmp_s.length())
        res = tmp_s;
        tmp_s = "";
        tmp = 0;
    }
    for (int i = 0; i < (int)res.length(); i++) {
        if (res[i] == '-' || (res[i] >= 'a' && res[i] <= 'z'))
            cout << res[i];
        else
            cout << (char)(res[i] - 'A' + 'a');
    }
}