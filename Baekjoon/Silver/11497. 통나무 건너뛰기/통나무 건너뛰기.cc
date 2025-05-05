#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int N, M, res;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        vector<int> v(M);
        for (int j = 0; j < M; j++)
            cin >> v[j];
        sort(v.begin(), v.end());
        res = abs(v[0] - v[1]);
        for (int j = 0; j < M; j++)
        {
            if (j + 2 < M)
            {
                if (res < abs(v[j] - v[j+2]))
                    res = abs(v[j] - v[j+2]);
            }
        }
        if (res < abs(v[M-1] - v[M-2]))
            res = abs(v[M-1] - v[M-2]);
        cout << res << '\n';
    }
}