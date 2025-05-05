#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int i = 1;
    int p, l ,v;
    while (true) {
        cin >> l >> p >> v;
        if (p == 0)
            break;
        int res = (v / p) * l + min((v%p), l);
        cout << "Case " << i << ": " << res << '\n';
        i++;
    }
}