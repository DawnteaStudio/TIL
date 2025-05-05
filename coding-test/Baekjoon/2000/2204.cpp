#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void cmp(string &res, string &tmp)
{
    int canChange = -1;
    int len = res.length();
    if (len > tmp.length())
        len = tmp.length();

    char c1, c2;
    for (int i = 0; i < len; i++) {
        if (res[i] == tmp[i])
            continue;
        c1 = res[i];
        c2 = tmp[i];
        if (res[i] >= 'a')
            c1 -= 32;
        if (tmp[i] >= 'a')
            c2 -= 32;
        if (c1 < c2)
            return;
        else if (c1 > c2) {
            res = tmp;
            return;
        }
        else {
            if (res[i] > tmp[i] && canChange != -1)
                canChange = 1;
            else if (res[i] < tmp[i] && canChange != -1)
                canChange = 0;

        }
    }
    if (canChange == 1) {
        res = tmp;
        return;
    }
    if (res.length() > tmp.length())
        res = tmp;
}

int main()
{
    fast;
    int input;
    string tmp, res;
    while (true) {
        cin >> input;
        res = "";
        if (input == 0)
            break;
        for (int i = 0; i < input; i++) {
            cin >> tmp;
            if (res.empty())
                res = tmp;
            else
                cmp(res, tmp);
        }
        cout << res << '\n';
    }
}