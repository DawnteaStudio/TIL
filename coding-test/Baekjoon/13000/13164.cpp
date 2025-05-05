#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, k, a, b, res = 0;
    cin >> n >> k;

    vector<int> vec(n - 1);
    cin >> a;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b;
        vec[i] = b - a;
        a = b;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - k; i++)
        res += vec[i];
    cout << res;
}
