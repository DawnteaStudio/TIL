#include <iostream>
#include <vector>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void solve(vector<int> &res, vector<int> &dp, int target, int idx)
{
    int s = 0;
    int e = res.size() - 1;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (res[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    res[s] = target;
    dp[idx] = s + 1;
}

int main()
{
    fast;
    int n;
    cin >> n;
    vector<int> res;
    vector<int> dp(n);

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    res.push_back(vec[0]);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (res.back() < vec[i]) {
            res.push_back(vec[i]);
            dp[i] = res.size();
        }
        else
            solve(res, dp, vec[i], i);
    }
    
    int size = res.size();
    cout << size << '\n';

    stack<int> lis;
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == size) {
            lis.push(vec[i]);
            size--;
        }
    }

    while (!lis.empty()) {
        cout << lis.top() << " ";
        lis.pop();
    }
}
