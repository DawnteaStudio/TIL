#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int mat1 [50][50] = {-1};
int mat2 [50][50] = {-1};

void change(int i, int j)
{
    for (int y = i; y < i + 3; y++)
    {
        for (int x = j; x < j + 3; x++)
        {
            if(mat1[y][x] == 1)
                mat1[y][x] = 0;
            else
                mat1[y][x] = 1;
        }
    }
}

int main()
{
    int N, M, elem, res = 0;
    string str;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
            mat1[i][j] = (int)str[j] - '0';
    }
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
            mat2[i][j] = (int)str[j] - '0';
    }
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if (mat1[i][j] != mat2[i][j])
            {
                change(i, j);
                res++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat1[i][j] != mat2[i][j])
            {
                cout << -1;
                return (0);
            }
        }
    }
    cout << res;
}
