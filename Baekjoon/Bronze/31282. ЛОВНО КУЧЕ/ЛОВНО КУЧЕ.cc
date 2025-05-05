#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, c;
    cin >> a >> b >> c;
    int res = (a / (c - b));

    if (a % (c - b) != 0)
        res++;
    cout << res;
}
