#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    int lx, rx, ly, ry;
    int tmp1, tmp2, tmp3, tmp4;
    for (int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        if (i == 0) {
            lx = tmp1;
            rx = tmp2;
            ly = tmp3;
            ry = tmp4;
        }
        else {
            lx = max(lx, tmp1);
            rx = min(rx, tmp2);
            ly = max(ly, tmp3);
            ry = min(ry, tmp4);
        }
    }
    if (lx > rx || ly > ry)
        cout << "0\n";
    else
        cout << (rx - lx) * (ry - ly) << "\n";
}
