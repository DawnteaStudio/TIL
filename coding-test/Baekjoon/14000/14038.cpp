#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    int cnt = 0;
    char n;
    for (int i = 0; i < 6; i++) {
        cin >> n;
        if (n == 'W')
            cnt++;
    }
    if (cnt >= 5)
        cout << 1;
    else if (cnt >= 3)
        cout << 2;
    else if (cnt >= 1)
        cout << 3;
    else
        cout << -1;
}
