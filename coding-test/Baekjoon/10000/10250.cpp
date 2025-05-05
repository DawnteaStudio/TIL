#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t, h, w, n, H, W;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;
        H = n % h;
        if (H == 0)
        {
            H = h;
            W = n / h;
        }
        else
            W = n / h + 1;
        cout << H;
        if (W < 10)
            cout << 0;
        cout << W;
        cout << '\n';
    }
}
