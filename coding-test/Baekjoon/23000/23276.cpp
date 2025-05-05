#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int getG(int a, int b)
{
    while (a * b != 0) {
        int tmp = min(a, b);

        a = a > b ? a % b : b % a;
        b = tmp;
    }
    return (a == 0 ? b : a);
}

int main()
{
    fast;
    int n, res = 0, year, G, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> year >> a >> b;
        G = getG(a, b);
        if (res == 0 || res > year + (a * b) / G)
            res = year + (a * b) / G;
    }
    cout << res;
}