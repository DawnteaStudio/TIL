#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int res = 0;
    int x, y, m;
    cin >> x >> y >> m;

    vector<bool> visited(m + 1, false);
    queue<int> q;
    q.push(x);
    q.push(y);
    while (!q.empty())
    {
        int now = q.front();
        if (now > res)
            res = now;
        q.pop();

        if (now >= m)
            continue;
        if (m >= now + x && visited[now + x] == false)
        {
            visited[now + x] = true;
            q.push(now + x);
        }
        if (m >= now + y && visited[now + y] == false)
        {
            visited[now + y] = true;
            q.push(now+y);
        }
    }
    cout << res;
}