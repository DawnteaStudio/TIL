#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

bool isin(int y, int x)
{
    if (y < 0 || x < 0 || y >= n || x >= m)
        return false;
    return true;
}

int main() {
    fast;

    cin >> n >> m;

    vector<string> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == '#') {
                int y, x;
                for (int k = 0; k < 4; k++) {
                    y = i + dy[k];
                    x = j + dx[k];
                    if (isin(y, x)) {
                        if (f[y][x] == '.')
                            res++;
                    }
                }
                if (i % 2 == 1) {
                    y = i + 1;
                    x = j + 1;
                    if (isin(y, x)) {
                        if (f[y][x] == '.')
                            res++;
                    }
                    y = i - 1;
                    x = j + 1;
                    if (isin(y, x)) {
                        if (f[y][x] == '.')
                            res++;
                    }
                }
                else {
                    y = i + 1;
                    x = j - 1;
                    if (isin(y, x)) {
                        if (f[y][x] == '.')
                            res++;
                    }
                    y = i - 1;
                    x = j - 1;
                    if (isin(y, x)) {
                        if (f[y][x] == '.')
                            res++;
                    }
                }
            }
        }
    }
    cout << res;
}
