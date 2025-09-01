#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int a, b, h;
    cin >> a >> b >> h;

    int cnt = 0;
    while (h > 0) {
        h -= a;
        cnt++;
        if (h <= 0)
            break;
        h += b;
    }
    cout << cnt;
}
