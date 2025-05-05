#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, cnt, res;
    cin >> a >> b;
    res = a + b;
    cnt = 0;
    while (res > 0)
    {
        res /= 10;
        cnt++;
    }
    cout << cnt;
    return (0);
}