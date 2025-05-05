#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main()
{
    fast;
    int n, a, b, res = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (vec[i] == 0)
            continue;
        if (b > a)
            res += b - a;
    }
    cout << res;
}