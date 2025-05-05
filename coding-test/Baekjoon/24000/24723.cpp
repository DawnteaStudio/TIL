#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        res *= 2;
    cout << res;
}