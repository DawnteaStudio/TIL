#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t, n, m, res;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        res = 0;
        int cnt, sticker;
        cin >> n >> m;
        vector<int> ans(n + 1, -1);
        vector<int> costs(n + 1);
        vector<int> stickers(m + 1);

        for (int j = 1; j <= n; j++)
        {
            cin >> cnt;
            for (int k = 0; k < cnt; k++)
            {
                cin >> sticker;
                stickers[sticker] = j;
            }
            cin >> costs[j];
        }

        for (int j = 1; j <= m; j++)
        {
            cin >> cnt;
            if (ans[stickers[j]] == -1 || ans[stickers[j]] > costs[stickers[j]] * cnt)
                ans[stickers[j]] = costs[stickers[j]] * cnt;
        }
        for (int j = 1; j <= n; j++)
        {
            if (ans[j] != -1)
                res += ans[j];
        }
        cout << res << '\n';
    }
}