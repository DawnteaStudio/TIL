#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int cnt=0, max_cnt=0;

    int a, b;
    for (int i=0; i<4; i++) {
        cin >> a >> b;
        cnt = max(cnt - a, 0);
        cnt += b;
        max_cnt = max(max_cnt, cnt);
    }
    cout << max_cnt;
}