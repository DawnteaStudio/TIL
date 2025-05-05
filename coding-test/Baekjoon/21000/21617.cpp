#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    double res = 0;
    cin >> n;
    vector<int> h(n + 1);
    vector<int> w(n);
    for (int i = 0; i < n + 1; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        res += (h[i] + h[i + 1]) * w[i];
    cout << fixed;
    cout.precision(7);
    cout << res / 2.0;
}