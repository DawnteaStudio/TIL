#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++)
    {
        sum += a[n - 1 - i] - a[i];
    }
    cout << sum << '\n';
}
