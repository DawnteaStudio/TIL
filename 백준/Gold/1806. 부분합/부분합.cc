#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, s, total = 0;
    cin >> n >> s;
    int res = n + 1;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    int f = -1, b = -1;
    while (b < n && f <= b) {
        if (total < s) {
            b++;
            total += vec[b];
        }
        else {
            f++;
            total -= vec[f];
        }

        if (total >= s)
            res = min(res, b - f);
    }
    if (res <= n)
        cout << res;
    else
        cout << 0;
}
