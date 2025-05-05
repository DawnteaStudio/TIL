#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    long long res = 0;
    long long tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        res += tmp;
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (tmp)
            res *= tmp;
    }
    cout << res;
}