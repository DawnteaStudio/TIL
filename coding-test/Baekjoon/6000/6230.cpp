#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    fast;
    int n, m, idx = 0;
    cin >> n >> m;
    int res = n;
    
    vector<int> high(n);
    vector<int> low(m);
    for (int i = 0; i < n; i++)
        cin >> high[i];
    for (int i = 0; i < m; i++)
        cin >> low[i];
    sort(high.begin(), high.end(), cmp);
    sort(low.begin(), low.end(), cmp);

    for (int i = 0; i < m; i++) {
        if (low[i] < high[idx]) {
            res++;
            idx++;
        }
        if (idx >= n)
            break;
    }
    cout << res;
}