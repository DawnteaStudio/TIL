#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;

void solve(vector<int> &vec, vector<int> &visited, int depth)
{
    if (depth == n) {
        for (int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i - 1] == 1)
            continue;
        vec[depth] = i;
        visited[i - 1] = 1;
        solve(vec, visited, depth + 1);
        visited[i - 1] = 0;
    }
}

int main()
{
    fast;
    cin >> n;

    vector<int> vec(n);
    vector<int> visited(n, 0);
    solve(vec, visited, 0);
}

