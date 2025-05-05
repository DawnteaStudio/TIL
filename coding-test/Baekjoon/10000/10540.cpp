#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, max_x = 0, max_y = 0, min_x = 101, min_y = 101;
    int x, y;
    cin >> n;

    for (int i = 0; i < n ; i++)
    {
        cin >> x >> y;
        if (x > max_x)
            max_x = x;
        if (x < min_x)
            min_x = x;
        if (y > max_y)
            max_y = y;
        if (y < min_y)
            min_y = y;
    }
    int res = (max_x - min_x) > (max_y - min_y) ? (max_x - min_x) : (max_y - min_y);
    cout << res * res;
}