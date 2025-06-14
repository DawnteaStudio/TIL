#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    int numList[n];
    for (int i = 0; i < n; i++)
        cin >> numList[i];

    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int cnt = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (numList[j - 1] >= numList[j])
                break;
            cnt++;
        }
        res = max(res, cnt);
    }
    cout << res;
    return (0);
}