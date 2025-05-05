#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
int n;

void    solve(vector<int> &vec, vector<int> comb, vector<bool> &visited, bool &res, int depth)
{
    if (!res)
        return;
    if (depth == 3)
    {
        if ((comb[0] - comb[1]) % comb[2] != 0)
            res = false;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true)
            continue;
        visited[i] = true;
        comb[depth] = vec[i];
        solve(vec, comb, visited, res, depth + 1);
        visited[i] = false;
    }
}

int main()
{
    fast;
    bool res = true;
    cin >> n;
    vector<int> vec(n);
    vector<int> comb(3, -1);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    solve(vec, comb, visited, res, 0);
    if (res)
        cout << "yes";
    else
        cout << "no";
}