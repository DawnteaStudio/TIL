#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cnt[7][2];

int main()
{
    fast;

    int n, k;
    cin >> n >> k;

    int sex, level;
    for (int i = 0; i < n; i++) {
        cin >> sex >> level;
        cnt[level][sex]++; 
    }

    int res = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            res += cnt[i][j] / k;
            if (cnt[i][j] % k)
                res++;
        }
    }
    cout << res;
}
