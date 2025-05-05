#include <string>
#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, M, res = 0;
    char c;
    int tmp;
    cin >> N >> M;

    vector<vector<char> > v(N, vector<char>(M));
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    string str;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
            v[i][j] = str[j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == true)
                continue;
            visited[i][j] = true;
            if (v[i][j] == '-')
            {
                tmp = j + 1;
                while(tmp < M && v[i][tmp] == '-' && visited[i][tmp] == false)
                {
                    visited[i][tmp] = true;
                    tmp++;
                }
                res++;
            }
            else
            {
                tmp = i + 1;
                while(tmp < N && v[tmp][j] == '|' && visited[tmp][j] == false)
                {
                    visited[tmp][j] = true;
                    tmp++;
                }
                res++;
            }
        }
    }
    cout << res;
}
