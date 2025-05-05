#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int visited[50][50];
int person[50];
string arr[50];

void find_friend(int n, int i, int j)
{
    for (int k = 0; k < n; k++)
    {
        if (arr[j][k] == 'Y')
        {
            if (arr[i][k] == 'Y' && visited[i][j] == 0)
            {
                person[i]++;
                person[j]++;
                visited[i][j] = 1;
                visited[j][i] = 1;
            }
        }
    }
}

int main()
{
    fast;
    int n;
    int res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && i != j)
            {
                if (arr[i][j] == 'Y')
                {
                    person[i]++;
                    person[j]++;
                    visited[i][j] = 1;
                    visited[j][i] = 1;
                }
                else
                    find_friend(n, i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
        res = (res < person[i] ? person[i] : res);
    cout << res;
}
