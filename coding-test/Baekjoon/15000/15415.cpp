#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, w, area = 0;
    cin >> w >> n;

    int wi, li;
    for (int i = 0; i < n; i++)
    {
        cin >> wi >> li;
        area += wi * li;
    }
    cout << area / w;
}
