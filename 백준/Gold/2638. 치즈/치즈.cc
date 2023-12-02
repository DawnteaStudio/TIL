#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct pos
{
    int y, x;
};
int graph[100][100];
int outair[100][100] = {0};
bool visited[100][100] = {false};
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int N, M, cnt;

void bfs()
{
    queue<pos> q;
    int x, y;
    q.push({0,0});

    while(!q.empty())
    {
        pos tmp = q.front();
        y = tmp.y;
        x = tmp.x;
        q.pop();
        if (visited[y][x])
            continue;
        visited[y][x] = true;

        for (int i = 0; i < 4; i++)
        {
            if (y + dy[i] < 0 || x + dx[i] < 0 || y + dy[i] >= N || x + dx[i] >= M)
                continue;
            if (graph[y + dy[i]][x + dx[i]] == 1)
                outair[y + dy[i]][x + dx[i]]++;
            else if(visited[y + dy[i]][x + dx[i]] == false)
                q.push({y + dy[i], x + dx[i]});
        }
    }
}

bool check()
{
    bool melted = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            if(outair[i][j] >= 2)
            {
                graph[i][j] = 0;
                melted = true;
            }
    }
    return melted;
}

void clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            outair[i][j] = 0;
        }
    }
}

int main()
{
    fast;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];
    }
    while(1)
    {
        clear();
        bfs();
        if(check())
            cnt++;
        else
            break;
    }
    cout << cnt;
}