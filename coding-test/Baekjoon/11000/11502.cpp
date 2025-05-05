#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool flag;

void    get_prime(vector<int> &prime, int t)
{
    for (int i = prime.back() + 1; i <= t; i++)
    {
        for (int j = 0; j < prime.size(); j++)
        {
            if (i % prime[j] == 0)
                break;
            if (j == prime.size() -1)
                prime.push_back(i);
        }
    }
}

void    solve(vector<int> &prime, vector<int> &ans, int index, int t, int sum, int depth)
{
    if (flag)
        return;
    if (sum > t)
        return;
    if (depth == 3)
    {
        if (sum == t)
        {
            flag = true;
            for (int i = 0; i < 3; i++)
                cout << ans[i] << " ";
            cout << '\n';
        }
        else
            return;
    }
    for (int i = index; i < prime.size(); i++)
    {
        ans[depth] = prime[i];
        solve(prime, ans, i, t, sum + prime[i], depth + 1);
    }
}

int main() {
    fast;
    int n, t;
    cin >> n;

    vector<int> prime(1, 2);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        flag = false;
        vector<int> ans(3);
        if (prime.back() < t)
            get_prime(prime, t);
        solve(prime, ans, 0, t, 0, 0);
        if (!flag)
            cout << 0 << '\n';
    }
}
