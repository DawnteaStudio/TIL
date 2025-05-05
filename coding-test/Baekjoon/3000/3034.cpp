#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, w, h, tmp;
    cin >> n >> w >> h;

    int line = (w * w) + (h * h);

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > w && tmp > h && (tmp * tmp) > line)
            cout << "NE" << '\n';
        else
            cout << "DA" << '\n';
    }
}