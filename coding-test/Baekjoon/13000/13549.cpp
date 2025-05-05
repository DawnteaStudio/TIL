#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    push_node(map<int, int> &visited, int value, int res, int k, int cost)
{
    if (value < 0 || value - k > res)
        return false;
    if (visited.find(value) == visited.end())
    {
        visited[value] = cost;
        return true;
    }
    else if (visited.find(value)->second > cost)
    {
        visited.find(value)->second = cost;
        return true;
    }
    return false;
}

int main() {
    fast;
    int n, k;
    cin >> n >> k;

    int res = abs(n - k);
    queue<pair<int, int> > q;
    map<int, int> visited;
    q.push(make_pair(n, 0));
    visited[n] = 0;
    while (!q.empty())
    {
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (now == k)
        {
            if (cost < res)
                res = cost;
        }
        if (now < k)
        {
            if (push_node(visited, now * 2, res, k, cost))
                q.push(make_pair(now * 2, cost));
            if (push_node(visited, now + 1, res, k, cost + 1))
                q.push(make_pair(now + 1, cost + 1));
            if (push_node(visited, now - 1, res, k, cost + 1))
                q.push(make_pair(now - 1, cost + 1));
        }
        else
        {
            if (res > now - k + cost)
                res = now - k + cost;
        }
    }
    cout << res;
}