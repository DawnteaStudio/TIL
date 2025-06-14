#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 0, tmp, low = 1000000001;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp < low)
        {
            low = tmp;
            res = i;
        }
    }
    cout << res;
}
