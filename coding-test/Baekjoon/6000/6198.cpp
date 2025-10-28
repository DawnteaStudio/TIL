#include <iostream>
#include <stack>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    stack<int> s;
    stack<pair<int, int> > dp;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s.push(tmp);
    }

    long long res = 0;
    
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int top = s.top();
        s.pop();

        while (!dp.empty() && dp.top().first < top) {
            res += dp.top().second;
            cnt += dp.top().second + 1;
            dp.pop();
        }
        dp.push({top, cnt});
    }

    while (!dp.empty()) {
        res += dp.top().second;
        dp.pop();
    }
    cout << res;
}
