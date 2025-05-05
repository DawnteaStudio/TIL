#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;

    int n, m, start_x, start_y, end_x, end_y, num, res;
    cin >> n >> m;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (j == 0)
                arr[i][j] = num;
            else if (j != 0)
                arr[i][j] = arr[i][j - 1] + num;
        }

    for (int i = 0; i < m; i++)
    {
        cin >> start_x >> start_y >> end_x >> end_y;
        res = 0;
        for (int j = start_x - 1; j <= end_x - 1; j++)
        {
            if (start_y != 1)
                res += (arr[j][end_y - 1] - arr[j][start_y - 2]);
            else
                res += arr[j][end_y - 1];
        }
        cout << res << '\n';
    }
}
