#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, k, w, v;
    cin >> n >> k;

    vector<vector<int> > vec(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> w >> v;
        for (int j = 1; j <= k; j++)
        {
            if (w > j)
                vec[i][j] = vec[i - 1][j];
            else if (vec[i - 1][j - w] + v > vec[i - 1][j])
                vec[i][j] = vec[i - 1][j - w] + v;
            else
                vec[i][j] = vec[i - 1][j];
        }
    }
    cout << vec[n][k];
}
