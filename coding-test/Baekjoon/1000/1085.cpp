#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int x, y, w, h, res;
    cin >> x >> y >> w >> h;

    res = x > y ? y : x;
    res = res > w - x ? w - x : res;
    res = res > h - y ? h - y : res;
    cout << res;
}
