#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, k, cnt = 0;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int start = 0, end = n - 1;
    
    while (start < end)
    {
        if (v[start] + v[end] <= k)
        {
            cnt++;
            start++;
            end--;
        }
        else
            end--;
    }
    cout << cnt;
}