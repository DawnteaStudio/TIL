#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string s;
    cin >> s;

    int len = s.length();

    for (int i = 0; i < len; i++) {
        string p = s.substr(i);

        int s = 0;
        int e = len - i - 1;

        while (s <= e) {
            if (p[s] == p[e]) {
                s++;
                e--;
            }
            else
                break;
        }
        if (s > e) {
            cout << len + i;
            break;
        }
    }
}

