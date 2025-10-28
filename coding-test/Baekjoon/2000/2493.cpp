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

    stack<pair<int, int> > s;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        while (!s.empty() && s.top().first < tmp) {
            s.pop();
        }

        if (s.empty()) {
            s.push({tmp, i});
            cout << 0;
        }
        else {
            cout << s.top().second;
            s.push({tmp, i});
        }
        cout << " ";
    }
}
