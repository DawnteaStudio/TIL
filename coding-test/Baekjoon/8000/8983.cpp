#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

bool hit(ll sade, ll l, ll x, ll y)
{
    return l >= abs(sade - x) + y;
}

int main() {
    fast;
    int m, n, res = 0;
    ll l;
    cin >> m >> n >> l;

    vector<int> sade(m);
    for (int i = 0; i < m; i++)
        cin >> sade[i];
    sort(sade.begin(), sade.end());
    ll x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (y > l)
            continue;
        int start = 0, end = m - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (hit(sade[mid], l, x, y) == true)
            {
                res++;
                break;
            }
            else
            {
                if (sade[mid] < x)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
    }
    cout << res;
}
