#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, remove, res = 0;
    cin >> n;
    if (n == 0)
        cout << 0;
    else
    {
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        remove = round(n * 0.15);
        sort(vec.begin(), vec.end());

        for (int i = remove; i < n - remove; i++)
            res += vec[i];
        res = round((double)res / (n - (2 * remove)));
        cout << res;
    }
}