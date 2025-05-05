#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, shelf, ans;

void solve(vector<int> &cows, int tmp, int depth)
{
    if (tmp > shelf && tmp > ans && ans > shelf)
        return;
    if (depth == n) {
        if (tmp >= shelf) {
            if (ans < shelf)
                ans = tmp;
            else {
                if (ans > tmp)
                    ans = tmp;
            }
        }
    }
    else {
        solve(cows, tmp + cows[depth], depth + 1);
        solve(cows, tmp, depth + 1);
    }
}

int main()
{
    fast;
    cin >> n >> shelf;

    vector<int> cows(n);
    for (int i = 0; i < n; i++)
        cin >> cows[i];
    solve(cows, 0, 0);
    cout << ans - shelf;
}
