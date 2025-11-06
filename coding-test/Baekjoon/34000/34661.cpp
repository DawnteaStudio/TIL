#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check(int y, int x, vector<vector<char> > &vec)
{
    if (y + 3 >= vec.size() || x + 3 >= vec[0].size())
        return false;
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            if (vec[i][j] == 'x')
                return false;
        }
    }

    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++)
            vec[i][j] == 'x';
    }
    return true;
}

int main()
{
    fast;
    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        int cnt = 0;

        vector<vector<char> > vec(n, vector<char>(m));
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < m; q++)
                cin >> vec[p][q];
        }
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < m; q++) {
                if (vec[p][q] == '.') {
                    if (check(p, q, vec) == false)
                        vec[p][q] = 'x';
                    cnt++;
                }
            }
        }
        if (cnt % 2)
            cout << "sewon\n";
        else
            cout << "pizza\n";
    }
}
