#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;

    int H, M;
    cin >> H >> M;

    if (M < 45)
    {
        M += 60;
        H--;
    }
    if (H < 0)
        H = 23;
    cout << H << ' ' << M - 45;
}
