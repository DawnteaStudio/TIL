#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    if ((c - a1) * n0 - a0 >= 0)
    {
        if (c < a1)
            cout << 0;
        else
            cout << 1;
    }
    else
        cout << 0;
}
