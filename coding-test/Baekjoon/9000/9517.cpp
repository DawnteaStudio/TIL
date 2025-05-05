#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int start;
    int n, t, cnt = 0;
    char c;

    cin >> start >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> c;
        cnt += t;
        if (cnt > 210) {
            cout << start;
            break;
        }
        if (c == 'T')
            start = start % 8 + 1;
    }
}