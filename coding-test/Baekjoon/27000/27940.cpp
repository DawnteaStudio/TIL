#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, m, k, res = 0;
    bool end = false;
    cin >> n >> m >> k;

    int floor, rain, tmp;
    for (int i = 1; i <= m; i++)
    {
        cin >> floor >> rain;
        res += rain;
        if (res > k)
        {
            end = true;
            cout << i << " " << 1;
            break;
        }
    }
    if (!end)
        cout << -1;
}