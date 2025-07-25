#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, m;
    cin >> n >> m;

    int now = 0, tmp;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (now + tmp > m) {
            cnt++;
            now = tmp;
        }
        else
            now += tmp;
    }
    if (now > 0)
        cnt++;
    cout << cnt;
}

