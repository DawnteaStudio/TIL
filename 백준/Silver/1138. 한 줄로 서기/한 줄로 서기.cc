#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, seq;
    cin >> n;

    vector<int> res(n, n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> seq;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (res[j] < i)
                continue;
            if (seq == cnt) {
                res[j] = i;
                break;
            }
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}

