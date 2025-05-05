#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        long long tmp = 0.0;
        for (long long j=1; j<=n; j++)
            tmp += (j * (j + 1) / 2);
        string res = to_string(tmp);
        cout << res.substr(0, res.find('.')) << '\n';
    }
    return (0);
}