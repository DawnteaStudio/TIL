#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = 1;
    int before = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] < before)
            res++;
        before = v[i];
    }
    cout << res;
}