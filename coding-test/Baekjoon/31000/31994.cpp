#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    string res, tmp;
    int n = 0, m;
    for (int i = 0; i < 7; i++) {
        cin >> tmp >> m;
        if (m > n) {
            n = m;
            res = tmp;
        }
    }
    cout << res;
}
