#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <queue>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool visited[10001];

void bfs(pair<int, string> node, int goal)
{
    queue<pair<int, string> > q;
    pair<int, string> tmp, nodes;
    q.push(node);
    visited[node.first] = true;

    while (!q.empty())
    {
        nodes = q.front();
        q.pop();
        if (nodes.first == goal)
        {
            cout << nodes.second << '\n';
            break;
        }
        tmp = nodes;
        tmp.first = (nodes.first * 2) % 10000;
        tmp.second += "D";
        if (visited[tmp.first] == false)
        {
            visited[tmp.first] = true;
            q.push(tmp);
        }
        tmp = nodes;
        if (nodes.first == 0)
            tmp.first = 9999;
        else
            tmp.first--;
        tmp.second += "S";
        if (visited[tmp.first] == false)
        {
            visited[tmp.first] = true;
            q.push(tmp);
        }
        tmp = nodes;
        tmp.first = (nodes.first % 1000) * 10 + (nodes.first / 1000);
        tmp.second += "L";
        if (visited[tmp.first] == false)
        {
            visited[tmp.first] = true;
            q.push(tmp);
        }
        tmp = nodes;
        tmp.first = (nodes.first / 10) + (nodes.first % 10) * 1000;
        tmp.second += "R";
        if (visited[tmp.first] == false)
        {
            visited[tmp.first] = true;
            q.push(tmp);
        }
    }
}

int main()
{
    fast;
    int N, num, goal;
    pair<int, string> node;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num >> goal;
        node = {num, ""};
        memset(visited, false, sizeof(visited));
        bfs(node, goal);
    }
}
