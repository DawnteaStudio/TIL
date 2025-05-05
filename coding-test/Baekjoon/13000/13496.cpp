#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int n, s, d, sum = 0, di, vi;
        cin >> n >> s >> d;
        for (int j = 0; j < n; j++)
        {
            cin >> di >> vi;
            if (di <= s * d)
                sum += vi;
        }
        cout << "Data Set " << i << ":\n";
        cout << sum << '\n';
        cout << '\n';
    }
}
