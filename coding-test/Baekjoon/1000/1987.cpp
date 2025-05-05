#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int r, c, res;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void    solve(vector<string> &vec, vector<bool> &visited, int y, int x, int step)
{
    if (step > res)
        res = step;
    for (int i = 0; i < 4; i++)
    {
        int new_y = y + dy[i];
        int new_x = x + dx[i];

        if (new_y < 0 || new_x < 0 || new_y >= r || new_x >= c)
            continue;
        int alpha = vec[new_y][new_x] - 'A';
        if (visited[alpha] == false)
        {
            visited[alpha] = true;
            solve(vec, visited, new_y, new_x, step + 1);
            visited[alpha] = false;
        }
    }
}

int main() {
    fast;
    cin >> r >> c;

    vector<string> vec(r);
    vector<bool> visited(26, false);
    for (int i = 0; i < r; i++)
        cin >> vec[i];
    visited[vec[0][0] - 'A'] = true;
    solve(vec, visited, 0, 0, 1);
    cout << res;
}