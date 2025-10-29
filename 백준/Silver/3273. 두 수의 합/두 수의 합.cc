#include <iostream>
#include <algorithm>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;

    int n, x;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    cin >> x;

    int l = 0, r = n - 1;
    int cnt = 0;
    while (l < r)
    {
        int sum = vec[l] + vec[r];
        if (sum == x)
            cnt++;
        if (sum <= x)
            l++;
        else
            r--;
    }
    cout << cnt;
}
