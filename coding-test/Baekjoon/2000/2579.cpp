#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<vector<int> > res(2, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    res[0][0] = vec[0];
    res[1][0] = vec[0];
    for (int i = 1; i < n; i++)
    {
        if (i == 1)
        {
            res[0][i] = vec[i];
            res[1][i] = vec[i] + vec[i - 1];
        }
        else
        {
            res[0][i] = max(res[0][i - 2], res[1][i - 2]) + vec[i];
            res[1][i] = max(res[0][i - 1], res[1][i - 2]) + vec[i];
        }
    }
    cout << max(res[0][n - 1], res[1][n - 1]);
}
