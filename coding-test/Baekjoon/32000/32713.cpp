#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    int res = 0;

    for (int i = 0; i < n; i++) {
        int tar = vec[i], tmp = 0, diff = 0;
        for (int j = i; j < n; j++) {
            if (vec[j] == tar)
                tmp++;
            else
                diff++;
            if (diff > k)
                break;
            if (tmp > res)
                res = tmp;
        }
    }
    cout << res;
}
