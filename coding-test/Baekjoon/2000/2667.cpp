#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dfs(vector<vector<bool> > &visited, vector<vector<int> > v, int i, int j, int N)
{   
    int res = 1;
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {-1, 0, 1, 0};
    for (int k = 0; k < 4; k++)
    {
        if (dy[k] + i < 0 || dx[k] + j < 0 || dy[k] + i >= N || dx[k] + j >= N)
            continue;
        if (v[dy[k] + i][dx[k] + j] == 1 && visited[dy[k] + i][dx[k] + j] == false)
        {
            visited[dy[k] + i][dx[k] + j] = true;
            res += dfs(visited, v, dy[k] + i, dx[k] + j, N);
        }
    }
    return (res);
}

int main()
{
    fast;
    int N;
    int res = 0;
    string str;
    cin >> N;

    vector<vector<int> > v(N, vector<int>(N));
    vector<vector<bool> > visited(N, vector<bool>(N, false));
    vector<int> size;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for(int j = 0; j < N; j++)
            v[i][j] = str[j] - '0';
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (v[i][j] == 1 && visited[i][j] == false)
            {
                res++;
                visited[i][j] = true;
                size.push_back(dfs(visited, v, i, j, N));
            }
            else
                continue;
        }
    }
    cout << res << '\n';
    sort(size.begin(), size.end());
    for (int k = 0; k < size.size(); k++)
    {
        cout << size[k] << '\n';
    }
}
