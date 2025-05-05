#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    cmp(int a, int b)
{
    return a > b;
}

int main() {
    fast;
    int n, b, res = 0, h = 0;
    cin >> n >> b;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end(), cmp);
    while (h < b)
    {
        h += vec[res];
        res++;
    }
    cout << res;
}
