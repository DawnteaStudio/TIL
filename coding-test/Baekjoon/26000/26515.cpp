#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int n;
    cin >> n;
    string line;
    getline(cin, line);

    for (int ds = 0; ds < n; ds++) {
        getline(cin, line);

        string s;
        long long val = 0;
        bool inNumber = false;
        bool neg = false;

        auto flushNumber = [&](void) {
            if (!inNumber) return;
            long long x = neg ? -val : val;

            if (x >= 65 && x <= 90) {
                s.push_back(char(x + 32));
            } else if (x >= 97 && x <= 122) {
                s.push_back(char(x));
            } else {
                s.push_back('-');
            }

            val = 0;
            inNumber = false;
            neg = false;
        };

        for (int i = 0; i < (int)line.size(); i++) {
            char c = line[i];
            if (c == '-' && !inNumber) {
                neg = true;
                inNumber = true;
                val = 0;
            } else if (c >= '0' && c <= '9') {
                if (!inNumber) {
                    inNumber = true;
                    neg = false;
                    val = 0;
                }
                val = val * 10 + (c - '0');
            } else
                flushNumber();
        }
        flushNumber();
        if (!s.empty()) {
            char first = s[0];
            string pig = s.substr(1);
            pig.push_back(first);
            pig += "ay";
            cout << pig << "\n";
        } else
            cout << "\n";
    }

}
