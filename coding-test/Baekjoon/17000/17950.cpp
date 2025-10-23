#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define MOD 1000000007

int main()
{
    fast;
    int h, x;
    cin >> h >> x;

    vector<int> vec(h);
    for (int i = 0; i < h; i++)
        cin >> vec[i];

    long long res = 0;

    for (int i = h - 1; i >= 0; i--) {
        res = res * x + vec[i];
        res %= MOD;
    }
    cout << (res * x) % MOD;
}
