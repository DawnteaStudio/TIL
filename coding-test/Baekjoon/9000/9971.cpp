#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void print(string &s) {
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
                if (s[i] - 5 < 'A')
                    cout << (char)(s[i] - 5 + 26);
                else
                    cout << (char)(s[i] - 5);
        }
        else
            cout << s[i];
    }
    cout << '\n';
}

int main()
{
    fast;
    string s;
    while (true) {
        getline(cin, s);
        if (s == "START")
            continue;
        if (s == "END")
            continue;
        if (s == "ENDOFINPUT")
            break;
        print(s);
    }
}
