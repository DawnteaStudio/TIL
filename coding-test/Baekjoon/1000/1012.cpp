#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int T;

void find_area(int M, int N, int **graph, bool **visited, int y, int x)
{
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {-1, 0, 1, 0};
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        if(y + dy[i] < 0 || x + dx[i] < 0 || y + dy[i] >= M || x + dx[i] >= N)
            continue;
        if(graph[y + dy[i]][x + dx[i]] == 1 && visited[y + dy[i]][x + dx[i]] == false)
        {
            visited[y+dy[i]][x+dx[i]] = true;
            find_area(M, N, graph, visited, y + dy[i], x +dx[i]);
        }
    }
}

int dfs(int M, int N, int **graph, bool **visited)
{
    int res = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(graph[i][j] == 1 && visited[i][j] == false)
            {
                res++;
                find_area(M, N, graph, visited, i, j);
            }
        }
    }
    return res;
}

int solve()
{
    int M, N, K, y, x;
    int res = 0;
    cin >> M >> N >> K;

    int **graph = new int*[M];
    bool **visited = new bool*[M];

    for (int i = 0; i < M; i++)
    {
        graph[i] = new int[N]{0};
        visited[i] = new bool[N]{false};
    }

    for (int i = 0; i < K; i++)
    {
        cin >> y >> x;
        graph[y][x] = 1;
    }

    res = dfs(M, N, graph, visited);

    for (int i = 0; i < M; i++)
    {
        delete[] graph[i];
        delete[] visited[i];
    }
    delete[] graph;
    delete[] visited;

    return res;
}

int main()
{
    fast;
    cin >> T;

    for (int i = 0; i < T; i++)
        cout << solve() << '\n';
}