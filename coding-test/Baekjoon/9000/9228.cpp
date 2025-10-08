#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main() {
    fast;

    string s;
    string arrow = " -> ";
    while (1) {
        cin >> s;
        int w = 2;
        if (s == "#")
            break;
        int len = s.length();
        int res = 0;
        for (int i = len - 1; i >= 0; i--)
            res += (s[i] - '0') * w++;
        int c = 11 - res % 11;
        cout << s << arrow;
        if (c == 11)
            cout << 0 << '\n';
        else if (c == 10)
            cout << "Rejected\n";
        else
            cout << c << '\n';
    }
}
