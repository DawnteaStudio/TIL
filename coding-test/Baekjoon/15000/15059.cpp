#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
    fast;
    int a, b, c, A, B, C, res = 0;
    cin >> a >> b >> c >> A >> B >> C;
    if (a < A)
        res += A - a;
    if (b < B)
        res += B - b;
    if (c < C)
        res += C - c;
    cout << res;
}
