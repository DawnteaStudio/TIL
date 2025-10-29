#include <iostream>
#include <vector>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    stack<pair<int, int> > s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        while (!s.empty() && s.top().first < tmp) {
            ans[s.top().second] = tmp;
            s.pop();
        }
        s.push({tmp, i});
    }
    while (!s.empty()) {
        ans[s.top().second] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
