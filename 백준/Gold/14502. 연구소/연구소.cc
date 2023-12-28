#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N, M, max_num;
int matrix[8][8];
int tmp[8][8];
bool include[8][8];
bool visited[8][8];
int buff[3][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void tmp_clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            tmp[i][j] = matrix[i][j];
    }
}

void visited_clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            visited[i][j] = false;
    }
}

void cal_max()
{
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp[i][j] == 0)
                num++;
        }
    }
    if (num > max_num)
        max_num = num;
}

void dfs(int y, int x)
{
    int new_y;
    int new_x;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        new_y = y + dy[i];
        new_x = x + dx[i];
        if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= M)
            continue;
        if (tmp[new_y][new_x] == 0)
        {
            tmp[new_y][new_x] = 2;
            dfs(new_y, new_x);
        }
    }
}

void search_virus()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp[i][j] == 2 && visited[i][j] == false)
                dfs(i, j);
        }
    }
}

void make_wall()
{
    int wall_y, wall_x;
    for (int i = 0; i < 3; i++)
    {
        wall_y = buff[i][0];
        wall_x = buff[i][1];
        tmp[wall_y][wall_x] = 1;
    }
}

void all_case_wall(int depth)
{
    if (depth == 3)
    {
        tmp_clear();
        make_wall();
        visited_clear();
        search_virus();
        cal_max();
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] != 0 || include[i][j] == true)
                continue;
            include[i][j] = true;
            buff[depth][0] = i;
            buff[depth][1] = j;
            all_case_wall(depth + 1);
            include[i][j] = false;
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
            cin >> matrix[i][j];
    }
    all_case_wall(0);
    cout << max_num;
}
