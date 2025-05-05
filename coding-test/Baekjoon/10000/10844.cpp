#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define DIV 1000000000

int main()
{
    fast;

    int n;
    long long res = 0;
    cin >> n;
    vector<vector<long long>> v(n, vector<long long>(10, 0));
    for (int i = 1; i < 10; i++)
        v[0][i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                v[i][j] = v[i - 1][1] % DIV;
            else if (j == 9)
                v[i][j] = v[i - 1][8] % DIV;
            else
                v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % DIV;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        res += v[n - 1][i];
        res %= DIV;
    }
    cout << res % DIV;
}
