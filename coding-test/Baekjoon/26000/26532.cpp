#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int w, h;
    cin >> w >> h;
    int area = w * h;
    int res;

    double acres = area / 4840.;
    res = acres / 5;
    if (acres > res * 5)
        res++;
    cout << res;
}
