#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int r, c, e, n, res = 0;
    cin >> r >> c >> e >> n;

    vector<vector<int> > vec(r, vector<int>(c));
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j++)
            cin >> vec[i][j];
    }

    int y, x, stamp;
    for (int i = 0; i < n; i++) {
        cin >> y >> x >> stamp;
        y--;
        x--;
        int max_h = 0;
        for (int p = y; p < y + 3; p++) {
            for (int q = x; q < x + 3; q++) {
                if (vec[p][q] > max_h)
                    max_h = vec[p][q];
            }
        }

        for (int p = y; p < y + 3; p++) {
            for (int q = x; q < x + 3; q++) {
                if (vec[p][q] > max_h - stamp)
                    vec[p][q] = max_h - stamp;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vec[i][j] < e)
                res += e - vec[i][j];
        }
    }
    cout << res * 72 * 72;
}
